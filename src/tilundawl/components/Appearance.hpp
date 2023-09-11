#ifndef TILUNDAWL_HEADER__COMPONENTS__APPEARANCE
#	define TILUNDAWL_HEADER__COMPONENTS__APPEARANCE

#	include <xieite/graphics/Color.hpp>

namespace tilundawl::components {
	struct Appearance {
		char texture;
		xieite::graphics::Color color;

		Appearance(const char texture, const xieite::graphics::Color color) noexcept;
	};
}

#endif
