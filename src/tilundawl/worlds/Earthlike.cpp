#include <tilundawl/components/Position.hpp>
#include <tilundawl/tiles/Air.hpp>
#include <tilundawl/worlds/Earthlike.hpp>
#include <tilundawl/worlds/templates/World.hpp>

tilundawl::worlds::Earthlike::Earthlike(const tilundawl::components::Position size) noexcept
: tilundawl::worlds::templates::World("Earthlike", size, tilundawl::tiles::Air()) {}
