#ifndef TILUNDAWL_HEADER__ENTITIES__PLAYER
#	define TILUNDAWL_HEADER__ENTITIES__PLAYER

#	include "../components/Position.hpp"
#	include "../entities/templates/Entity.hpp"

namespace tilundawl::entities {
	class Player
	: public tilundawl::entities::templates::Entity {
	public:
		Player(const tilundawl::components::Position position) noexcept;
	};
}

#endif
