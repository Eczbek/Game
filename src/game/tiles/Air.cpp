#include <game/components/Appearance.hpp>
#include <game/tiles/Air.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

game::tiles::Air::Air() noexcept
: game::tiles::templates::Tile("Air", false, false, true, game::components::Appearance('.', xieite::graphics::Color(127, 127, 127))) {}
