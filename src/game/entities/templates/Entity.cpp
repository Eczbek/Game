#include <game/components/Appearance.hpp>
#include <game/components/Direction.hpp>
#include <game/components/Position.hpp>
#include <game/entities/templates/Entity.hpp>
#include <string_view>
#include <xieite/random/getUUID.hpp>

game::entities::templates::Entity::Entity(const std::string_view typeName, const bool isAbleToModifyTiles, const game::components::Position position, const game::components::Appearance& appearance) noexcept
: typeName(typeName), uuid(xieite::random::getUUID()), isAbleToModifyTiles(isAbleToModifyTiles), position(position), direction(0, 0), appearance(appearance) {}

std::string_view game::entities::templates::Entity::getTypeName() const noexcept {
	return typeName;
}

std::string_view game::entities::templates::Entity::getUUID() const noexcept {
	return uuid;
}

bool game::entities::templates::Entity::getAbilityToModifyTiles() const noexcept {
	return isAbleToModifyTiles;
}

game::components::Position game::entities::templates::Entity::getPosition() const noexcept {
	return position;
}

void game::entities::templates::Entity::setPosition(const game::components::Position newPosition) noexcept {
	position = newPosition;
}

game::components::Direction game::entities::templates::Entity::getDirection() const noexcept {
	return direction;
}

void game::entities::templates::Entity::setDirection(const game::components::Direction newDirection) noexcept {
	direction = newDirection;
}

const game::components::Appearance& game::entities::templates::Entity::getAppearance() const noexcept {
	return appearance;
}
