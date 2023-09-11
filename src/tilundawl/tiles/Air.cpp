#include <tilundawl/components/Appearance.hpp>
#include <tilundawl/tiles/Air.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

tilundawl::tiles::Air::Air() noexcept
: tilundawl::tiles::templates::Tile("Air", false, false, true, tilundawl::components::Appearance('.', xieite::graphics::Color(127, 127, 127))) {}
