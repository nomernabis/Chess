cmake_minimum_required(VERSION 3.9)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess main.cpp Game.h Game.cpp pieces/Piece.cpp pieces/Piece.h pieces/Pawn.cpp pieces/Pawn.h pieces/Rook.h pieces/Rook.cpp pieces/Bishop.cpp pieces/Bishop.h pieces/Queen.cpp pieces/Queen.h pieces/King.cpp pieces/King.h pieces/Knight.cpp pieces/Knight.h TextureHolder.cpp TextureHolder.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Chess ${SFML_LIBRARIES})
endif()