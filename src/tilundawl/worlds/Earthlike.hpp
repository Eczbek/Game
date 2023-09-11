#ifndef TILUNDAWL_HEADER__WORLDS__EARTHLIKE
#	define TILUNDAWL_HEADER__WORLDS__EARTHLIKE

#	include "../components/Position.hpp"
#	include "../worlds/templates/World.hpp"

namespace tilundawl::worlds {
	class Earthlike
	: public tilundawl::worlds::templates::World {
	public:
		Earthlike(const tilundawl::components::Position size) noexcept;
	};
}

#endif
