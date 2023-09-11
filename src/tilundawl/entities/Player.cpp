#include <tilundawl/components/Appearance.hpp>
#include <tilundawl/components/Position.hpp>
#include <tilundawl/entities/Player.hpp>
#include <tilundawl/entities/templates/Entity.hpp>
#include <xieite/graphics/Color.hpp>

tilundawl::entities::Player::Player(const tilundawl::components::Position position) noexcept
: tilundawl::entities::templates::Entity("Player", true, position, tilundawl::components::Appearance('@', xieite::graphics::Color(255, 0, 0))) {}
