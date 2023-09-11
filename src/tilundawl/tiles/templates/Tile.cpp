#include <tilundawl/components/Appearance.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <string_view>

tilundawl::tiles::templates::Tile::Tile(const std::string_view typeName, const bool isSolid, const bool isMovable, const bool isReplaceable, const tilundawl::components::Appearance& appearance) noexcept
: typeName(typeName), isSolid(isSolid), isMovable(isMovable), isReplaceable(isReplaceable), appearance(appearance) {}

std::string_view tilundawl::tiles::templates::Tile::getTypeName() const noexcept {
	return typeName;
}

bool tilundawl::tiles::templates::Tile::getSolidity() const noexcept {
	return isSolid;
}

bool tilundawl::tiles::templates::Tile::getMovability() const noexcept {
	return isMovable;
}

bool tilundawl::tiles::templates::Tile::getReplaceability() const noexcept {
	return isReplaceable;
}

const tilundawl::components::Appearance& tilundawl::tiles::templates::Tile::getAppearance() const noexcept {
	return appearance;
}
