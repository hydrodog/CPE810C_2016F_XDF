cmake_minimum_required (VERSION 2.8.11)
project (xdf)
SET(CMAKE_CXX_STANDARD 11)

add_subdirectory (pdf)
add_subdirectory (2dgraphics)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED COMPONENTS Core Gui)
get_target_property(QtCore_location Qt5::Core LOCATION)
MESSAGE("Found Qt5Core library in ${QtCore_location}")

