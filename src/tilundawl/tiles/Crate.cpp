#include <xieite/graphics/Color.hpp>
#include "../components/Appearance.hpp"
#include "../tiles/Crate.hpp"
#include "../tiles/templates/Tile.hpp"

tilundawl::tiles::Crate::Crate() noexcept
: tilundawl::tiles::templates::Tile("Crate", true, true, false, tilundawl::components::Appearance('O', xieite::graphics::Color(255, 127, 0))) {}
