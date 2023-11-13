cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe VERSION 1.0)
add_executable(tictaccore src/ttt_commandline.cpp)

if(QT_GUI)
    message("Qt GUI Enabled")
else()
    message("Qt not enabled")
endif()
