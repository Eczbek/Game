#include <game/components/Appearance.hpp>
#include <game/tiles/Stone.hpp>
#include <game/tiles/templates/Tile.hpp>
#include <xieite/graphics/Color.hpp>

game::tiles::Stone::Stone() noexcept
: game::tiles::templates::Tile("Stone", true, false, false, game::components::Appearance('#', xieite::graphics::Color(255, 255, 255))) {}
