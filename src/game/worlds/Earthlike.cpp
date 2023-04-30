#include <game/components/Position.hpp>
#include <game/tiles/Air.hpp>
#include <game/worlds/Earthlike.hpp>
#include <game/worlds/templates/World.hpp>

game::worlds::Earthlike::Earthlike(const game::components::Position size) noexcept
: game::worlds::templates::World("Earthlike", size, game::tiles::Air()) {}
