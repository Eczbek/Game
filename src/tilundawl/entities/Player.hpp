#pragma once

#include <tilundawl/components/Position.hpp>
#include <tilundawl/entities/templates/Entity.hpp>

namespace tilundawl::entities {
	class Player
	: public tilundawl::entities::templates::Entity {
	public:
		Player(const tilundawl::components::Position position) noexcept;
	};
}
