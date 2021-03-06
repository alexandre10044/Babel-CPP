if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there")
endif ()

cmake_minimum_required(VERSION 3.5.1)
project(babel)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-fPIC")

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS}")
else()
    set(STANDARD_UNIX_CXX_FLAGS "-Wall -g3 -Wextra -Wfatal-errors")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${STANDARD_UNIX_CXX_FLAGS}")
endif()

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
else()
    message(FATAL_ERROR "No conanbuildinfo.cmake file found")
endif()

#include(CMakeSources.cmake)

conan_basic_setup()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS client/ui)


find_package(Qt5OpenGL CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)


include_directories("${PROJECT_SOURCE_DIR}/client/include/")
include_directories("${PROJECT_SOURCE_DIR}/server/include/")
file(GLOB_RECURSE SOURCES_CLIENT RELATIVE ${CMAKE_SOURCE_DIR} "client/sources/*.cpp")
file(GLOB_RECURSE SOURCES_SERVER RELATIVE ${CMAKE_SOURCE_DIR} "server/sources/*.cpp")

# UI.h  PATH
include_directories(build)

set(QT_GUI
        ${PROJECT_SOURCE_DIR}/client/ui/widget.ui
        )
qt5_wrap_ui(QT_GUI_H ${QT_GUI})

#qt5_wrap_cpp(moc_sources ${PROJECT_SOURCE_DIR}/client/include/widget.h)
#qt5_wrap_cpp(moc_sources /client/include/TCPConnect.hpp)

#${moc_sources}

add_executable(babel_client ${SOURCES_CLIENT}  ${QT_GUI_H})
add_executable(babel_server ${SOURCES_SERVER} ${MOC_SRCS})
install(TARGETS babel_client DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS babel_server DESTINATION ${PROJECT_SOURCE_DIR}/bin)

#############################################################
target_link_libraries(babel_client ${CONAN_LIBS}
        Qt5::OpenGL Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)
target_include_directories(babel_client PRIVATE inc ../common/inc)

target_link_libraries(babel_server ${CONAN_LIBS})
target_include_directories(babel_server PRIVATE inc ../common/inc)