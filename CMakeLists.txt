cmake_minimum_required(VERSION 3.26.3)

set(PROJECT game)
project(${PROJECT} VERSION 0.0.0)

add_executable(${PROJECT}
	src/game/components/Appearance.cpp
	src/game/components/Direction.cpp
	src/game/components/Position.cpp
	src/game/entities/templates/Entity.cpp
	src/game/entities/Player.cpp
	src/game/tiles/templates/Tile.cpp
	src/game/tiles/Air.cpp
	src/game/tiles/Crate.cpp
	src/game/tiles/Stone.cpp
	src/game/worlds/templates/World.cpp
	src/game/worlds/Earthlike.cpp
	src/main.cpp
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC uuid)
