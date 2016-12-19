cmake_minimum_required (VERSION 2.8.11)
project (xdf)
SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(PODOFO_BUILD_SHARED TRUE)
set(PODOFO_BUILD_LIB_ONLY TRUE)

# include directories
SET(XDFGRAPHICS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/2dgraphics/Source_beta")
SET(PDFIMPORT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pdf/pdfimport")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
)
add_subdirectory(pdf)
add_subdirectory(2dgraphics)
add_subdirectory(test)
MESSAGE("++++++++++++++PODOFO_DEPEND_TARGET ${PODOFO_DEPEND_TARGET}")
