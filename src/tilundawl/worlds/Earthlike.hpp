#pragma once

#include <tilundawl/components/Position.hpp>
#include <tilundawl/worlds/templates/World.hpp>

namespace tilundawl::worlds {
	class Earthlike
	: public tilundawl::worlds::templates::World {
	public:
		Earthlike(const tilundawl::components::Position size) noexcept;
	};
}
