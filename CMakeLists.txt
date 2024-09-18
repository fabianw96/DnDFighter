cmake_minimum_required(VERSION 3.29)
project(CPPConsoleProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPPConsoleProject main.cpp
 "MonsterFactory.cpp" "MonsterFactory.h" "EntityData.h" "EntityData.cpp"
        Weapon.cpp
        Weapon.h
        HelperMacros.h
        Game.cpp
        Game.h
)
