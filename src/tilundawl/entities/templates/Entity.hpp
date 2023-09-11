#ifndef TILUNDAWL_HEADER__ENTITIES__TEMPLATES__ENTITY
#	define TILUNDAWL_HEADER__ENTITIES__TEMPLATES__ENTITY

#	include <string>
#	include <string_view>
#	include "../../components/Appearance.hpp"
#	include "../../components/Direction.hpp"
#	include "../../components/Position.hpp"

namespace tilundawl::entities::templates {
	class Entity {
	private:
		std::string typeName;
		std::string identifier;
		bool isAbleToModifyTiles;
		tilundawl::components::Position position;
		tilundawl::components::Direction direction;
		tilundawl::components::Appearance appearance;

	public:
		Entity(const std::string_view typeName, const bool isAbleToModifyTiles, const tilundawl::components::Position position, const tilundawl::components::Appearance& appearance) noexcept;

		std::string_view getTypeName() const noexcept;

		std::string_view getIdentifier() const noexcept;

		bool getAbilityToModifyTiles() const noexcept;

		tilundawl::components::Position getPosition() const noexcept;

		void setPosition(const tilundawl::components::Position newPosition) noexcept;

		tilundawl::components::Direction getDirection() const noexcept;

		void setDirection(const tilundawl::components::Direction newDirection) noexcept;

		const tilundawl::components::Appearance& getAppearance() const noexcept;
	};
}

#endif
