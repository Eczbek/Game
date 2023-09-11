#ifndef TILUNDAWL_HEADER__TILES__STONE
#	define TILUNDAWL_HEADER__TILES__STONE

#	include "../tiles/templates/Tile.hpp"

namespace tilundawl::tiles {
	class Stone
	: public tilundawl::tiles::templates::Tile {
	public:
		Stone() noexcept;
	};
}

#endif
