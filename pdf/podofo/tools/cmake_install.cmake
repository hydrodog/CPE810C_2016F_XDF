# Install script for directory: /Users/Leigh/Desktop/localpdf/pdf/podofo/tools

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofobox/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofocolor/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofocountpages/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofocrop/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoencrypt/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofogc/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoimgextract/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoimg2pdf/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofomerge/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofopages/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofopdfinfo/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofotxt2pdf/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofotxtextract/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofouncompress/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoimpose/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoincrementalupdates/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/podofoxmp/cmake_install.cmake")
  include("/Users/Leigh/Desktop/localpdf/pdf/podofo/tools/xdfimport/cmake_install.cmake")

endif()

