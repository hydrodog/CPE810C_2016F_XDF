add_library(xdfgraphics
    operatordictrie.cpp
    exceptionoptdic.cpp
    twodgraphics.cpp
    drawfunlist.cpp
    shape.cpp
    exceptiontwodg.cpp
    tod.cpp
)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
TARGET_LINK_LIBRARIES(xdfgraphics  Qt5::Core  Qt5::Gui Qt5::Widgets)
