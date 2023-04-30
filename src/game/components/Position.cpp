#include <cstddef>
#include <game/components/Position.hpp>

game::components::Position::Position(const std::size_t x, const std::size_t y) noexcept
: x(x), y(y) {}
