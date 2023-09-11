#ifndef TILUNDAWL_HEADER__TILES__TEMPLATES__TILE
#	define TILUNDAWL_HEADER__TILES__TEMPLATES__TILE

#	include <string>
#	include <string_view>
#	include "../../components/Appearance.hpp"

namespace tilundawl::tiles::templates {
	class Tile {
	private:
		std::string typeName;
		bool isSolid;
		bool isMovable;
		bool isReplaceable;
		tilundawl::components::Appearance appearance;

	public:
		Tile(const std::string_view typeName, const bool isSolid, const bool isMovable, const bool isReplaceable, const tilundawl::components::Appearance& appearance) noexcept;

		std::string_view getTypeName() const noexcept;

		bool getSolidity() const noexcept;

		bool getMovability() const noexcept;

		bool getReplaceability() const noexcept;

		const tilundawl::components::Appearance& getAppearance() const noexcept;
	};
}

#endif
