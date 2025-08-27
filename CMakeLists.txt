cmake_minimum_required(VERSION 4.0)

set(PROJECT_NAME Meat)
set(TARGET_NAME meat)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)

add_executable(${TARGET_NAME}
        src/main.cpp
        src/core/window.cpp
        src/core/renderer.cpp
        src/game/game.cpp
        src/systems/input_system.cpp
)

find_package(SDL3 REQUIRED)

target_link_libraries(${TARGET_NAME} PRIVATE SDL3::SDL3)

target_include_directories(${TARGET_NAME} PRIVATE src)