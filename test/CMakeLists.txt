add_executable(testgraphics testgraphics.cpp)

#SET_TARGET_PROPERTIES(testgraphics PROPERTIES COMPILE_FLAGS "${PODOFO_CFLAGS}")
TARGET_LINK_LIBRARIES(testgraphics
    xdfgraphics
    pdfimport
    ${PODOFO_DEPEND_TARGET}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
ADD_DEPENDENCIES(testgraphics pdfimport ${PODOFO_DEPEND_TARGET})
include_directories(
    ${PoDoFo_SOURCE_DIR}
    ${XDFGRAPHICS_SOURCE_DIR}
    ${PDFIMPORT_SOURCE_DIR}
)

message("+++++++++ XDFGRAPHICS_SOURCE_DIR ${XDFGRAPHICS_SOURCE_DIR}")
message("+++++++++ PDFIMPORT_SOURCE_DIR ${PDFIMPORT_SOURCE_DIR}")

