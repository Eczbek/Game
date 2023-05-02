#pragma once

#include <game/components/Appearance.hpp>
#include <game/components/Direction.hpp>
#include <game/components/Position.hpp>
#include <string>
#include <string_view>

namespace game::entities::templates {
	class Entity {
	private:
		std::string typeName;
		std::string uuid;
		bool isAbleToModifyTiles;
		game::components::Position position;
		game::components::Direction direction;
		game::components::Appearance appearance;

	public:
		Entity(const std::string_view typeName, const bool isAbleToModifyTiles, const game::components::Position position, const game::components::Appearance& appearance) noexcept;

		std::string_view getTypeName() const noexcept;

		std::string_view getUUID() const noexcept;

		bool getAbilityToModifyTiles() const noexcept;

		game::components::Position getPosition() const noexcept;

		void setPosition(const game::components::Position newPosition) noexcept;

		game::components::Direction getDirection() const noexcept;

		void setDirection(const game::components::Direction newDirection) noexcept;

		const game::components::Appearance& getAppearance() const noexcept;
	};
}
