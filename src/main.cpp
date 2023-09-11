#include <chrono>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <xieite/functors/ScopeGuard.hpp>
#include <xieite/strings/lowercase.hpp>
#include <xieite/system/BufferPosition.hpp>
#include <xieite/system/terminal.hpp>
#include "./tilundawl/components/Appearance.hpp"
#include "./tilundawl/components/Position.hpp"
#include "./tilundawl/entities/Player.hpp"
#include "./tilundawl/entities/templates/Entity.hpp"
#include "./tilundawl/tiles/Crate.hpp"
#include "./tilundawl/tiles/Stone.hpp"
#include "./tilundawl/worlds/Earthlike.hpp"

int main() {
	const tilundawl::components::Position worldSize(10, 10);
	tilundawl::worlds::Earthlike world(worldSize);

	world.setTile(tilundawl::components::Position(3, 4), tilundawl::tiles::Stone());
	world.setTile(tilundawl::components::Position(2, 7), tilundawl::tiles::Crate());

	tilundawl::entities::Player player(tilundawl::components::Position(5, 6));
	const std::string playerIdentifier(player.getIdentifier());
	world.addEntity(player);

	xieite::system::terminal.setCursorAlternative(true);
	xieite::system::terminal.setScreenAlternative(true);
	// xieite::system::terminal.setCursorVisible(false);
	// xieite::system::terminal.setInputEcho(false);
	
	xieite::functors::ScopeGuard terminalGuard = xieite::functors::ScopeGuard([]() {
		xieite::system::terminal.setCursorVisible(true);
		xieite::system::terminal.setScreenAlternative(false);
		xieite::system::terminal.setCursorAlternative(false);
	});

	bool running = true;
	while (running) {
		std::vector<std::vector<tilundawl::components::Appearance>> display;
		for (std::size_t y = worldSize.y; y--;) {
			std::vector<tilundawl::components::Appearance>& displayRow = display.emplace_back();
			for (std::size_t x = 0; x < worldSize.x; ++x) {
				displayRow.push_back(world.getTile(tilundawl::components::Position(x, y)).getAppearance());
			}
		}
		for (const std::pair<std::string, tilundawl::entities::templates::Entity>& entryPair : world.getEntities()) {
			const tilundawl::entities::templates::Entity& entity = entryPair.second;
			const tilundawl::components::Appearance& appearance = entity.getAppearance();
			const tilundawl::components::Direction direction = entity.getDirection();
			const tilundawl::components::Position position = entity.getPosition();
			display[worldSize.y - position.y - 1][position.x] = appearance;
			display[worldSize.y - (position.y + direction.y + worldSize.y) % worldSize.y - 1][(position.x + direction.x + worldSize.x) % worldSize.x].color = appearance.color;
		}

		xieite::system::terminal.clearScreen();
		xieite::system::terminal.setCursorPosition(xieite::system::BufferPosition(0, 0));
		for (const std::vector<tilundawl::components::Appearance>& displayRow : display) {
			for (const tilundawl::components::Appearance& appearance : displayRow) {
				xieite::system::terminal.setForegroundColor(appearance.color);
				std::cout << appearance.texture << ' ';
			}
			xieite::system::terminal.resetStyles();
			std::cout << "\n\r";
		}

		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		const xieite::system::BufferPosition arrowInput = xieite::system::terminal.readArrow();
		if (arrowInput.row || arrowInput.column) {
			world.controlEntity(playerIdentifier, tilundawl::components::Direction(arrowInput.column, -arrowInput.row));	
		} else {
			switch (xieite::strings::lowercase(xieite::system::terminal.readCharacter())) {
				case 'q':
					running = false;
					break;
				case 'd':
					world.controlEntity(playerIdentifier, tilundawl::components::Direction(1, 0));
					break;
				case 'a':
					world.controlEntity(playerIdentifier, tilundawl::components::Direction(-1, 0));
					break;
				case 'w':
					world.controlEntity(playerIdentifier, tilundawl::components::Direction(0, 1));
					break;
				case 's':
					world.controlEntity(playerIdentifier, tilundawl::components::Direction(0, -1));
					break;
				case 'x':
					world.controlEntity(playerIdentifier, tilundawl::components::Direction(0, 0));
					break;
			}
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
}
