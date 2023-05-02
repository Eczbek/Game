#pragma once

#include <game/components/Position.hpp>
#include <game/entities/templates/Entity.hpp>

namespace game::entities {
	class Player
	: public game::entities::templates::Entity {
	public:
		Player(const game::components::Position position) noexcept;
	};
}
