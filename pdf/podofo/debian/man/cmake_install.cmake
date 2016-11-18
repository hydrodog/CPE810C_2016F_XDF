# Install script for directory: /Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/podofo")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofobox.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofocolor.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofocountpages.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofocrop.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofogc.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoencrypt.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoimg2pdf.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoimgextract.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoimpose.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoincrementalupdates.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofomerge.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofopages.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofopdfinfo.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofotxt2pdf.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofotxtextract.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofouncompress.1"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/debian/man/podofoxmp.1"
    )
endif()

