#pragma once

#include <tilundawl/components/Direction.hpp>
#include <tilundawl/components/Position.hpp>
#include <tilundawl/entities/templates/Entity.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace tilundawl::worlds::templates {
	class World {
	private:
		std::string typeName;
		tilundawl::components::Position size;
		tilundawl::tiles::templates::Tile defaultTile;
		std::vector<std::vector<tilundawl::tiles::templates::Tile>> tiles;
		std::unordered_map<std::string, tilundawl::entities::templates::Entity> entities;

	public:
		World(const std::string_view typeName, const tilundawl::components::Position size, const tilundawl::tiles::templates::Tile& defaultTile) noexcept;

		std::string_view getTypeName() const noexcept;

		tilundawl::components::Position getSize() const noexcept;

		const std::vector<std::vector<tilundawl::tiles::templates::Tile>>& getTiles() const noexcept;

		const tilundawl::tiles::templates::Tile& getTile(const tilundawl::components::Position position) const noexcept;

		tilundawl::tiles::templates::Tile& getTile(const tilundawl::components::Position position) noexcept;

		void setTile(const tilundawl::components::Position position, const tilundawl::tiles::templates::Tile& tile) noexcept;

		void removeTile(const tilundawl::components::Position position) noexcept;

		void pushTiles(const tilundawl::components::Position startPosition, const tilundawl::components::Direction direction) noexcept;

		const std::unordered_map<std::string, tilundawl::entities::templates::Entity>& getEntities() const noexcept;

		const tilundawl::entities::templates::Entity& getEntity(const std::string& uuid) const noexcept;

		tilundawl::entities::templates::Entity& getEntity(const std::string& uuid) noexcept;

		void addEntity(tilundawl::entities::templates::Entity entity) noexcept;

		void removeEntity(const std::string& uuid) noexcept;

		void controlEntity(const std::string& uuid, const tilundawl::components::Direction newDirection) noexcept;
	};
}
