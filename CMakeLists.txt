cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe VERSION 1.0)
add_executable(tictaccore ttt_commandline.cpp)
