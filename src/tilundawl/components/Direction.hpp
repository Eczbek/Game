#ifndef TILUNDAWL_HEADER__COMPONENTS__DIRECTION
#	define TILUNDAWL_HEADER__COMPONENTS__DIRECTION

namespace tilundawl::components {
	struct Direction {
		int x;
		int y;

		Direction(int x, int y) noexcept;
	};
}

#endif
