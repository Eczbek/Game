#ifndef TILUNDAWL_HEADER__WORLDS__TEMPLATES__WORLD
#	define TILUNDAWL_HEADER__WORLDS__TEMPLATES__WORLD

#	include <string>
#	include <string_view>
#	include <unordered_map>
#	include <vector>
#	include "../../components/Direction.hpp"
#	include "../../components/Position.hpp"
#	include "../../entities/templates/Entity.hpp"
#	include "../../tiles/templates/Tile.hpp"

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

		const tilundawl::entities::templates::Entity& getEntity(const std::string& identifier) const noexcept;

		tilundawl::entities::templates::Entity& getEntity(const std::string& identifier) noexcept;

		void addEntity(tilundawl::entities::templates::Entity entity) noexcept;

		void removeEntity(const std::string& identifier) noexcept;

		void controlEntity(const std::string& identifier, const tilundawl::components::Direction newDirection) noexcept;
	};
}

#endif
