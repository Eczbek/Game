#include <game/components/Direction.hpp>
#include <game/components/Position.hpp>
#include <game/entities/templates/Entity.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <game/worlds/templates/World.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

game::worlds::templates::World::World(const std::string_view typeName, const game::components::Position size, const game::tiles::templates::Tile& defaultTile) noexcept
: typeName(typeName), size(size), defaultTile(defaultTile) {
	for (std::size_t x = 0; x < size.x; ++x) {
		std::vector<game::tiles::templates::Tile>& column = tiles.emplace_back();
		for (std::size_t y = 0; y < size.y; ++y) {
			column.push_back(defaultTile);
		}
	}
}

std::string_view game::worlds::templates::World::getTypeName() const noexcept {
	return typeName;
}

game::components::Position game::worlds::templates::World::getSize() const noexcept {
	return size;
}

const std::vector<std::vector<game::tiles::templates::Tile>>& game::worlds::templates::World::getTiles() const noexcept {
	return tiles;
}

const game::tiles::templates::Tile& game::worlds::templates::World::getTile(const game::components::Position position) const noexcept {
	return tiles[position.x % size.x][position.y % size.y];
}

game::tiles::templates::Tile& game::worlds::templates::World::getTile(const game::components::Position position) noexcept {
	return tiles[position.x % size.x][position.y % size.y];
}

void game::worlds::templates::World::setTile(const game::components::Position position, const game::tiles::templates::Tile& tile) noexcept {
	getTile(position) = tile;
}

void game::worlds::templates::World::removeTile(const game::components::Position position) noexcept {
	setTile(position, defaultTile);
}

void game::worlds::templates::World::pushTiles(const game::components::Position startPosition, const game::components::Direction direction) noexcept {
	game::components::Position endPosition = startPosition;
	do {
		endPosition.x = (endPosition.x + direction.x + size.x) % size.x;
		endPosition.y = (endPosition.y + direction.y + size.y) % size.y;
	} while (((endPosition.x != startPosition.x) || (endPosition.y != startPosition.y)) && tiles[endPosition.x][endPosition.y].getMovability());
	if (tiles[endPosition.x][endPosition.y].getReplaceability()) {
		for (std::size_t x = endPosition.x; x - startPosition.x; x = (x - direction.x + size.x) % size.x) {
			tiles[x][startPosition.y] = tiles[(x - direction.x + size.x) % size.x][startPosition.y];
		}
		for (std::size_t y = endPosition.y; y - startPosition.y; y = (y - direction.y + size.y) % size.y) {
			tiles[startPosition.x][y] = tiles[startPosition.x][(y - direction.y + size.y) % size.y];
		}
		tiles[startPosition.x][startPosition.y] = defaultTile;
	}
}

const std::unordered_map<std::string, game::entities::templates::Entity>& game::worlds::templates::World::getEntities() const noexcept {
	return entities;
}

const game::entities::templates::Entity& game::worlds::templates::World::getEntity(const std::string& uuid) const noexcept {
	return entities.at(uuid);
}

game::entities::templates::Entity& game::worlds::templates::World::getEntity(const std::string& uuid) noexcept {
	return entities.at(uuid);
}

void game::worlds::templates::World::addEntity(game::entities::templates::Entity entity) noexcept {
	const game::components::Position position = entity.getPosition();
	entity.setPosition(game::components::Position(position.x % size.x, position.y % size.y));
	entities.insert(std::make_pair(std::string(entity.getUUID()), entity));
}

void game::worlds::templates::World::removeEntity(const std::string& uuid) noexcept {
	entities.erase(uuid);
}

void game::worlds::templates::World::controlEntity(const std::string& uuid, const game::components::Direction newDirection) noexcept {
	game::entities::templates::Entity& entity = getEntity(uuid);
	const game::components::Direction direction = entity.getDirection();
	if (direction.x == newDirection.x && direction.y == newDirection.y) {
		const game::components::Position position = entity.getPosition();
		const game::components::Position newPosition((position.x + direction.x + size.x) % size.x, (position.y + direction.y + size.y) % size.x);
		if (entity.getAbilityToModifyTiles() && getTile(newPosition).getMovability()) {
			pushTiles(newPosition, direction);
		}
		if (!getTile(newPosition).getSolidity()) {
			entity.setPosition(newPosition);
		}
	}
	entity.setDirection(newDirection);
}
