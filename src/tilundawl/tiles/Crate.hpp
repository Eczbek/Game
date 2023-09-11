#ifndef TILUNDAWL_HEADER__TILES__CRATE
#	define TILUNDAWL_HEADER__TILES__CRATE

#	include "../tiles/templates/Tile.hpp"

namespace tilundawl::tiles {
	class Crate
	: public tilundawl::tiles::templates::Tile {
	public:
		Crate() noexcept;
	};
}

#endif
