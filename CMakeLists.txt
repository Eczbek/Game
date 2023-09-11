cmake_minimum_required(VERSION 3.27)

set(PROJECT_NAMESPACE tilundawl)
file(
	GLOB_RECURSE PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*
)
project(
	${PROJECT_NAMESPACE}
	VERSION 0.1.0
)
add_executable(
	${PROJECT_NAMESPACE} ${PROJECT_SOURCES}
)
target_compile_features(
	${PROJECT_NAMESPACE} PUBLIC
	cxx_std_23
)
target_include_directories(
	${PROJECT_NAMESPACE} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(
	${PROJECT_NAMESPACE} PUBLIC
	uuid
)
