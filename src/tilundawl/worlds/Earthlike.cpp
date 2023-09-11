#include "../components/Position.hpp"
#include "../tiles/Air.hpp"
#include "../worlds/Earthlike.hpp"
#include "../worlds/templates/World.hpp"

tilundawl::worlds::Earthlike::Earthlike(const tilundawl::components::Position size) noexcept
: tilundawl::worlds::templates::World("Earthlike", size, tilundawl::tiles::Air()) {}
