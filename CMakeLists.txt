cmake_minimum_required(VERSION 3.29)
project(Monopoly_Board_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Monopoly_Board_game main.cpp
        Monopoly_Board.cpp
        Monopoly_Board.h)
