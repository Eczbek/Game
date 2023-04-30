#include <game/components/Appearance.hpp>
#include <xieite/graphics/Color.hpp>

game::components::Appearance::Appearance(const char texture, const xieite::graphics::Color color) noexcept
: texture(texture), color(color) {}
