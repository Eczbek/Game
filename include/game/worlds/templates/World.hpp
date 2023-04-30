#pragma once

#include <game/components/Direction.hpp>
#include <game/components/Position.hpp>
#include <game/entities/templates/Entity.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace game::worlds::templates {
	class World {
	private:
		std::string typeName;
		game::components::Position size;
		game::tiles::templates::Tile defaultTile;
		std::vector<std::vector<game::tiles::templates::Tile>> tiles;
		std::unordered_map<std::string, game::entities::templates::Entity> entities;

	public:
		World(const std::string_view typeName, const game::components::Position size, const game::tiles::templates::Tile& defaultTile) noexcept;

		std::string_view getTypeName() const noexcept;

		game::components::Position getSize() const noexcept;

		const std::vector<std::vector<game::tiles::templates::Tile>>& getTiles() const noexcept;

		const game::tiles::templates::Tile& getTile(const game::components::Position position) const noexcept;

		game::tiles::templates::Tile& getTile(const game::components::Position position) noexcept;

		void setTile(const game::components::Position position, const game::tiles::templates::Tile& tile) noexcept;

		void removeTile(const game::components::Position position) noexcept;

		void pushTiles(const game::components::Position startPosition, const game::components::Direction direction) noexcept;

		const std::unordered_map<std::string, game::entities::templates::Entity>& getEntities() const noexcept;

		const game::entities::templates::Entity& getEntity(const std::string& uuid) const noexcept;

		game::entities::templates::Entity& getEntity(const std::string& uuid) noexcept;

		void addEntity(game::entities::templates::Entity entity) noexcept;

		void removeEntity(const std::string& uuid) noexcept;

		void controlEntity(const std::string& uuid, const game::components::Direction newDirection) noexcept;
	};
}
