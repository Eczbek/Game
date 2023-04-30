#include <game/components/Appearance.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <string_view>

game::tiles::templates::Tile::Tile(const std::string_view typeName, const bool isSolid, const bool isMovable, const bool isReplaceable, const game::components::Appearance& appearance) noexcept
: typeName(typeName), isSolid(isSolid), isMovable(isMovable), isReplaceable(isReplaceable), appearance(appearance) {}

std::string_view game::tiles::templates::Tile::getTypeName() const noexcept {
	return typeName;
}

bool game::tiles::templates::Tile::getSolidity() const noexcept {
	return isSolid;
}

bool game::tiles::templates::Tile::getMovability() const noexcept {
	return isMovable;
}

bool game::tiles::templates::Tile::getReplaceability() const noexcept {
	return isReplaceable;
}

const game::components::Appearance& game::tiles::templates::Tile::getAppearance() const noexcept {
	return appearance;
}
