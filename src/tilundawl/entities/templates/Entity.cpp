#include <string_view>
#include <xieite/random/getUniversallyUniqueIdentifier.hpp>
#include "../../components/Appearance.hpp"
#include "../../components/Direction.hpp"
#include "../../components/Position.hpp"
#include "../../entities/templates/Entity.hpp"

tilundawl::entities::templates::Entity::Entity(const std::string_view typeName, const bool isAbleToModifyTiles, const tilundawl::components::Position position, const tilundawl::components::Appearance& appearance) noexcept
: typeName(typeName), identifier(xieite::random::getUniversallyUniqueIdentifier()), isAbleToModifyTiles(isAbleToModifyTiles), position(position), direction(0, 0), appearance(appearance) {}

std::string_view tilundawl::entities::templates::Entity::getTypeName() const noexcept {
	return typeName;
}

std::string_view tilundawl::entities::templates::Entity::getIdentifier() const noexcept {
	return identifier;
}

bool tilundawl::entities::templates::Entity::getAbilityToModifyTiles() const noexcept {
	return isAbleToModifyTiles;
}

tilundawl::components::Position tilundawl::entities::templates::Entity::getPosition() const noexcept {
	return position;
}

void tilundawl::entities::templates::Entity::setPosition(const tilundawl::components::Position newPosition) noexcept {
	position = newPosition;
}

tilundawl::components::Direction tilundawl::entities::templates::Entity::getDirection() const noexcept {
	return direction;
}

void tilundawl::entities::templates::Entity::setDirection(const tilundawl::components::Direction newDirection) noexcept {
	direction = newDirection;
}

const tilundawl::components::Appearance& tilundawl::entities::templates::Entity::getAppearance() const noexcept {
	return appearance;
}
