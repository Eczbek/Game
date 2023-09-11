#ifndef TILUNDAWL_HEADER__COMPONENTS__POSITION
#	define TILUNDAWL_HEADER__COMPONENTS__POSITION

#	include <cstddef>

namespace tilundawl::components {
	struct Position {
		std::size_t x;
		std::size_t y;

		Position(const std::size_t x, const std::size_t y) noexcept;
	};
}

#endif
