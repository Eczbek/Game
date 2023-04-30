#include <game/components/Appearance.hpp>
#include <game/components/Position.hpp>
#include <game/entities/Player.hpp>
#include <game/entities/templates/Entity.hpp>
#include <xieite/graphics/Color.hpp>

game::entities::Player::Player(const game::components::Position position) noexcept
: game::entities::templates::Entity("Player", true, position, game::components::Appearance('@', xieite::graphics::Color(255, 0, 0))) {}
