#include <tilundawl/components/Appearance.hpp>
#include <tilundawl/tiles/Stone.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

tilundawl::tiles::Stone::Stone() noexcept
: tilundawl::tiles::templates::Tile("Stone", true, false, false, tilundawl::components::Appearance('#', xieite::graphics::Color(255, 255, 255))) {}
