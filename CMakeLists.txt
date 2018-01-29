cmake_minimum_required(VERSION 3.9)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess main.cpp Game.h Game.cpp shapes/Shape.cpp shapes/Shape.h shapes/Pawn.cpp shapes/Pawn.h shapes/Rook.h shapes/Rook.cpp shapes/Bishop.cpp shapes/Bishop.h shapes/Queen.cpp shapes/Queen.h shapes/King.cpp shapes/King.h shapes/Knight.cpp shapes/Knight.h)