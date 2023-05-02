#pragma once

#include <xieite/graphics/Color.hpp>

namespace game::components {
	struct Appearance {
		char texture;
		xieite::graphics::Color color;

		Appearance(const char texture, const xieite::graphics::Color color) noexcept;
	};
}
