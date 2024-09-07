cmake_minimum_required(VERSION 3.29)
project(CPPConsoleProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPPConsoleProject main.cpp
 "MonsterFactory.cpp" "MonsterFactory.h"   "Monster.cpp" "Monster.h" "EntityData.h" "EntityData.cpp")
