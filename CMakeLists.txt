cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe VERSION 1.0)

if(QT_GUI)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(CMAKE_AUTOMOC ON)
    add_executable(tictactoe src/qt_main.cpp)
    target_link_libraries(tictactoe PRIVATE Qt5::Widgets)

    # Use windeployqt to copy required Qt DLLs
    add_custom_command(TARGET tictactoe POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E env
        ${WINDEPLOYQT_EXECUTABLE}
        --no-compiler-runtime
        --no-angle
        --no-opengl-sw
        --no-system-d3d-compiler
        --no-translations
        $<TARGET_FILE:tictactoe>
    )
    message("Qt GUI Enabled")
else()
    add_executable(tictactoe src/ttt_commandline.cpp)
    message("Qt not enabled. no GUI support")
endif()

install(TARGETS tictactoe DESTINATION bin)
