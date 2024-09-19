cmake_minimum_required(VERSION 3.29)
project(DnDFighter)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/raylib)

add_executable(DnDFighter main.cpp
 "MonsterFactory.cpp" "MonsterFactory.h" "EntityData.h" "EntityData.cpp"
        Weapon.cpp
        Weapon.h
        HelperMacros.h
        Game.cpp
        Game.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH"${CMAKE_CURRENT_SOURCE_DIR}/assets/")
