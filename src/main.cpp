#include <chrono>
#include <cstddef>
#include <game/components/Appearance.hpp>
#include <game/components/Position.hpp>
#include <game/entities/Player.hpp>
#include <game/entities/templates/Entity.hpp>
#include <game/tiles/Crate.hpp>
#include <game/tiles/Stone.hpp>
#include <game/worlds/Earthlike.hpp>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <xieite/terminal/ModeLock.hpp>
#include <xieite/terminal/Position.hpp>
#include <xieite/terminal/clearScreen.hpp>
#include <xieite/terminal/getString.hpp>
#include <xieite/terminal/resetStyle.hpp>
#include <xieite/terminal/setColorForeground.hpp>
#include <xieite/terminal/setCursorPosition.hpp>
#include <xieite/terminal/setCursorVisibility.hpp>
#include <xieite/terminal/setScreenAlternative.hpp>
#include <xieite/string/toLowercase.hpp>

int main() {
	game::worlds::Earthlike world(game::components::Position(10, 10));
	const game::components::Position worldSize = world.getSize();

	game::entities::Player player(game::components::Position(5, 7));
	const std::string playerUUID(player.getUUID());
	world.addEntity(player);

	world.setTile(game::components::Position(1, 0), game::tiles::Stone());
	world.setTile(game::components::Position(2, 1), game::tiles::Crate());

	std::cout
		<< xieite::terminal::setScreenAlternative(true)
		<< xieite::terminal::setCursorVisibility(false);

	xieite::terminal::ModeLock modeLock;
	modeLock.setBlocking(false);

	bool running = true;
	while (running) {
		std::vector<std::vector<game::components::Appearance>> display;
		for (std::size_t y = worldSize.y; y--;) {
			std::vector<game::components::Appearance>& displayRow = display.emplace_back();
			for (std::size_t x = 0; x < worldSize.x; ++x) {
				displayRow.push_back(world.getTile(game::components::Position(x, y)).getAppearance());
			}
		}
		for (const std::pair<std::string, game::entities::templates::Entity>& entryPair : world.getEntities()) {
			const game::entities::templates::Entity& entity = entryPair.second;
			const game::components::Appearance& appearance = entity.getAppearance();
			const game::components::Direction direction = entity.getDirection();
			const game::components::Position position = entity.getPosition();
			display[worldSize.y - position.y - 1][position.x] = appearance;
			display[worldSize.y - (position.y + direction.y + worldSize.y) % worldSize.y - 1][(position.x + direction.x + worldSize.x) % worldSize.x].color = appearance.color;
		}

		std::cout
			<< xieite::terminal::clearScreen()
			<< xieite::terminal::setCursorPosition(xieite::terminal::Position(0, 0));
		for (const std::vector<game::components::Appearance>& displayRow : display) {
			for (const game::components::Appearance& appearance : displayRow) {
				std::cout
					<< xieite::terminal::setColorForeground(appearance.color)
					<< appearance.texture
					<< ' ';
			}
			std::cout
				<< xieite::terminal::resetStyle()
				<< "\n\r";
		}

		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		const std::string input = xieite::terminal::getString();
		if (input.size()) {
			switch (xieite::string::toLowercase(input.back())) {
				case 'q':
					running = false;
					break;
				case 'd':
					world.controlEntity(playerUUID, game::components::Direction(1, 0));
					break;
				case 'a':
					world.controlEntity(playerUUID, game::components::Direction(-1, 0));
					break;
				case 'w':
					world.controlEntity(playerUUID, game::components::Direction(0, 1));
					break;
				case 's':
					world.controlEntity(playerUUID, game::components::Direction(0, -1));
					break;
				case 'x':
					world.controlEntity(playerUUID, game::components::Direction(0, 0));
					break;
			}
		}
	}

	std::cout
		<< xieite::terminal::setCursorVisibility(true)
		<< xieite::terminal::setScreenAlternative(false);
}
