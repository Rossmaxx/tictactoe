cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tictactoe VERSION 1.0)

if(QT_GUI)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(CMAKE_AUTOMOC ON)

    # get absolute path for qmake then use that path for windeployqt
    get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)

    # find windeployqt
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    add_executable(tictactoe src/qt_main.cpp)
    target_link_libraries(tictactoe PRIVATE Qt5::Widgets)

    # Add commands that copy the required Qt files to the same directory as the
    # target after being built as well as including them in final installation
    function(windeployqt target)

        # Run windeployqt immediately after build
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E
                env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
                    --verbose 0
                    --no-compiler-runtime
                    --no-angle
                    --no-opengl-sw
                    \"$<TARGET_FILE:${target}>\"
            COMMENT "Deploying Qt..."
        )

        set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
        include(InstallRequiredSystemLibraries)
        foreach(lib ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS})
            get_filename_component(filename "${lib}" NAME)
            add_custom_command(TARGET ${target} POST_BUILD
                COMMAND "${CMAKE_COMMAND}" -E
                    copy_if_different "${lib}" \"$<TARGET_FILE_DIR:${target}>\"
                COMMENT "Copying ${filename}..."
            )
        endforeach()
    endfunction()

    mark_as_advanced(WINDEPLOYQT_EXECUTABLE)

    message("Qt GUI Enabled")
else()
    add_executable(tictactoe src/ttt_commandline.cpp)
    message("Qt not enabled. no GUI support")
endif()

install(TARGETS tictactoe DESTINATION bin)
