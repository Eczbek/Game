#pragma once

#include <xieite/graphics/Color.hpp>

namespace tilundawl::components {
	struct Appearance {
		char texture;
		xieite::graphics::Color color;

		Appearance(const char texture, const xieite::graphics::Color color) noexcept;
	};
}
