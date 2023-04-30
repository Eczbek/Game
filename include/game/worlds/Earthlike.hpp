#pragma once

#include <game/components/Position.hpp>
#include <game/worlds/templates/World.hpp>

namespace game::worlds {
	class Earthlike
	: public game::worlds::templates::World {
	public:
		Earthlike(const game::components::Position size) noexcept;
	};
}
