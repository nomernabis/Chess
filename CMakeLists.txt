cmake_minimum_required(VERSION 3.9)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess main.cpp Game.h Game.cpp shapes/Shape.cpp shapes/Shape.h shapes/Pawn.cpp shapes/Pawn.h shapes/Rook.h shapes/Rook.cpp shapes/Bishop.cpp shapes/Bishop.h shapes/Queen.cpp shapes/Queen.h shapes/King.cpp shapes/King.h shapes/Knight.cpp shapes/Knight.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Chess ${SFML_LIBRARIES})
endif()