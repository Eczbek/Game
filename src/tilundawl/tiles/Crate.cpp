#include <tilundawl/components/Appearance.hpp>
#include <tilundawl/tiles/Crate.hpp>
#include <tilundawl/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

tilundawl::tiles::Crate::Crate() noexcept
: tilundawl::tiles::templates::Tile("Crate", true, true, false, tilundawl::components::Appearance('O', xieite::graphics::Color(255, 127, 0))) {}
