cmake_minimum_required(VERSION 2.43)
Project(Zeno-Survival-Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML COMPONENTS graphics audio network system window REQUIRED)

set(SOURCE src/Game.cpp src/State.cpp States/GameState.cpp headers/Engine/Object.cpp)

include_directories(headers/ States/)
add_executable(ZSP src/main.cpp ${SOURCE})

target_link_libraries(ZSP sfml-graphics sfml-audio sfml-system sfml-network sfml-window)