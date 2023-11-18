cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe VERSION 1.0)

if(QT_GUI)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(CMAKE_AUTOMOC ON)

    add_executable(tictactoe WIN32 src/qt_main.cpp)
    target_link_libraries(tictactoe PRIVATE Qt5::Widgets)

    message("Qt GUI Enabled")
else()
    add_executable(tictactoe src/ttt_commandline.cpp)
    message("Qt not enabled. no GUI support")
endif()

install(TARGETS tictactoe DESTINATION bin)
