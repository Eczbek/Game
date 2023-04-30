#pragma once

#include <cstddef>

namespace game::components {
	struct Position {
		std::size_t x;
		std::size_t y;

		Position(const std::size_t x, const std::size_t y) noexcept;
	};
}
