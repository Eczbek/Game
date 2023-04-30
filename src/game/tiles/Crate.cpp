#include <game/components/Appearance.hpp>
#include <game/tiles/Crate.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

game::tiles::Crate::Crate() noexcept
: game::tiles::templates::Tile("Crate", true, true, false, game::components::Appearance('O', xieite::graphics::Color(255, 127, 0))) {}
