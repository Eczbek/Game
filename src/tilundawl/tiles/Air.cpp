#include <xieite/graphics/Color.hpp>
#include "../components/Appearance.hpp"
#include "../tiles/Air.hpp"
#include "../tiles/templates/Tile.hpp"

tilundawl::tiles::Air::Air() noexcept
: tilundawl::tiles::templates::Tile("Air", false, false, true, tilundawl::components::Appearance('.', xieite::graphics::Color(127, 127, 127))) {}
