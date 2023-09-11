#include <xieite/graphics/Color.hpp>
#include "../components/Appearance.hpp"
#include "../components/Position.hpp"
#include "../entities/Player.hpp"
#include "../entities/templates/Entity.hpp"

tilundawl::entities::Player::Player(const tilundawl::components::Position position) noexcept
: tilundawl::entities::templates::Entity("Player", true, position, tilundawl::components::Appearance('@', xieite::graphics::Color(255, 0, 0))) {}
