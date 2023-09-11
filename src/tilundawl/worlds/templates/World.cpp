#include <tilundawl/components/Direction.hpp>
#include <tilundawl/components/Position.hpp>
#include <tilundawl/entities/templates/Entity.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <tilundawl/worlds/templates/World.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

tilundawl::worlds::templates::World::World(const std::string_view typeName, const tilundawl::components::Position size, const tilundawl::tiles::templates::Tile& defaultTile) noexcept
: typeName(typeName), size(size), defaultTile(defaultTile) {
	for (std::size_t x = 0; x < size.x; ++x) {
		std::vector<tilundawl::tiles::templates::Tile>& column = tiles.emplace_back();
		for (std::size_t y = 0; y < size.y; ++y) {
			column.push_back(defaultTile);
		}
	}
}

std::string_view tilundawl::worlds::templates::World::getTypeName() const noexcept {
	return typeName;
}

tilundawl::components::Position tilundawl::worlds::templates::World::getSize() const noexcept {
	return size;
}

const std::vector<std::vector<tilundawl::tiles::templates::Tile>>& tilundawl::worlds::templates::World::getTiles() const noexcept {
	return tiles;
}

const tilundawl::tiles::templates::Tile& tilundawl::worlds::templates::World::getTile(const tilundawl::components::Position position) const noexcept {
	return tiles[position.x % size.x][position.y % size.y];
}

tilundawl::tiles::templates::Tile& tilundawl::worlds::templates::World::getTile(const tilundawl::components::Position position) noexcept {
	return tiles[position.x % size.x][position.y % size.y];
}

void tilundawl::worlds::templates::World::setTile(const tilundawl::components::Position position, const tilundawl::tiles::templates::Tile& tile) noexcept {
	getTile(position) = tile;
}

void tilundawl::worlds::templates::World::removeTile(const tilundawl::components::Position position) noexcept {
	setTile(position, defaultTile);
}

void tilundawl::worlds::templates::World::pushTiles(const tilundawl::components::Position startPosition, const tilundawl::components::Direction direction) noexcept {
	tilundawl::components::Position endPosition = startPosition;
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

const std::unordered_map<std::string, tilundawl::entities::templates::Entity>& tilundawl::worlds::templates::World::getEntities() const noexcept {
	return entities;
}

const tilundawl::entities::templates::Entity& tilundawl::worlds::templates::World::getEntity(const std::string& identifier) const noexcept {
	return entities.at(identifier);
}

tilundawl::entities::templates::Entity& tilundawl::worlds::templates::World::getEntity(const std::string& identifier) noexcept {
	return entities.at(identifier);
}

void tilundawl::worlds::templates::World::addEntity(tilundawl::entities::templates::Entity entity) noexcept {
	const tilundawl::components::Position position = entity.getPosition();
	entity.setPosition(tilundawl::components::Position(position.x % size.x, position.y % size.y));
	entities.insert(std::make_pair(std::string(entity.getIdentifier()), entity));
}

void tilundawl::worlds::templates::World::removeEntity(const std::string& identifier) noexcept {
	entities.erase(identifier);
}

void tilundawl::worlds::templates::World::controlEntity(const std::string& identifier, const tilundawl::components::Direction newDirection) noexcept {
	tilundawl::entities::templates::Entity& entity = getEntity(identifier);
	const tilundawl::components::Direction direction = entity.getDirection();
	if (direction.x == newDirection.x && direction.y == newDirection.y) {
		const tilundawl::components::Position position = entity.getPosition();
		const tilundawl::components::Position newPosition((position.x + direction.x + size.x) % size.x, (position.y + direction.y + size.y) % size.x);
		if (entity.getAbilityToModifyTiles() && getTile(newPosition).getMovability()) {
			pushTiles(newPosition, direction);
		}
		if (!getTile(newPosition).getSolidity()) {
			entity.setPosition(newPosition);
		}
	}
	entity.setDirection(newDirection);
}
