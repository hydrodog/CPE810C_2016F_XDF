# Install script for directory: /home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofobox/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofocolor/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofocountpages/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofocrop/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoencrypt/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofogc/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoimgextract/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoimg2pdf/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofomerge/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofopages/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofopdfinfo/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofotxt2pdf/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofotxtextract/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofouncompress/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoimpose/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoincrementalupdates/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/podofoxmp/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/tools/xdfimport/cmake_install.cmake")

endif()

