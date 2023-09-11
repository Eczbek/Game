#ifndef TILUNDAWL_HEADER__TILES__AIR
#	define TILUNDAWL_HEADER__TILES__AIR

#	include "../tiles/templates/Tile.hpp"

namespace tilundawl::tiles {
	class Air
	: public tilundawl::tiles::templates::Tile {
	public:
		Air() noexcept;
	};
}

#endif
