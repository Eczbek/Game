#pragma once

#include <game/components/Appearance.hpp>
#include <string>
#include <string_view>

namespace game::tiles::templates {
	class Tile {
	private:
		std::string typeName;
		bool isSolid;
		bool isMovable;
		bool isReplaceable;
		game::components::Appearance appearance;

	public:
		Tile(const std::string_view typeName, const bool isSolid, const bool isMovable, const bool isReplaceable, const game::components::Appearance& appearance) noexcept;

		std::string_view getTypeName() const noexcept;

		bool getSolidity() const noexcept;

		bool getMovability() const noexcept;

		bool getReplaceability() const noexcept;

		const game::components::Appearance& getAppearance() const noexcept;
	};
}
