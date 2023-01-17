cmake_minimum_required(VERSION 2.43)
Project(Zeno-Survival-Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML COMPONENTS graphics audio network system window REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

file(GLOB SOURCE
    "${CMAKE_SOURCE_DIR}/src/*"
    "${CMAKE_SOURCE_DIR}/headers/*"
    "${CMAKE_SOURCE_DIR}/headers/*/*"
    "${CMAKE_SOURCE_DIR}/States/*")

include_directories(headers/ States/)
add_executable(ZSP src/main.cpp ${SOURCE})

target_link_libraries(ZSP sfml-graphics sfml-audio sfml-system sfml-network sfml-window)