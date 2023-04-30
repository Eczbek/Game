#include <algorithm>
#include <game/components/Direction.hpp>

game::components::Direction::Direction(const int x, const int y) noexcept
: x(std::clamp(x, -1, 1)), y(std::clamp(y, -1, 1)) {}
