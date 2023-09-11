#include <algorithm>
#include "../components/Direction.hpp"

tilundawl::components::Direction::Direction(const int x, const int y) noexcept
: x(std::clamp(x, -1, 1)), y(std::clamp(y, -1, 1)) {}
