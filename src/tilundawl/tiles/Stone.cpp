#include <xieite/graphics/Color.hpp>
#include "../components/Appearance.hpp"
#include "../tiles/Stone.hpp"
#include "../tiles/templates/Tile.hpp"

tilundawl::tiles::Stone::Stone() noexcept
: tilundawl::tiles::templates::Tile("Stone", true, false, false, tilundawl::components::Appearance('#', xieite::graphics::Color(255, 255, 255))) {}
