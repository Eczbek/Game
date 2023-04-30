#pragma once

namespace game::components {
	struct Direction {
		int x;
		int y;

		Direction(int x, int y) noexcept;
	};
}
