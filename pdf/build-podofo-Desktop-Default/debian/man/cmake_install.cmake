# Install script for directory: /home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofobox.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofocolor.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofocountpages.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofocrop.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofogc.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoencrypt.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoimg2pdf.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoimgextract.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoimpose.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoincrementalupdates.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofomerge.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofopages.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofopdfinfo.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofotxt2pdf.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofotxtextract.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofouncompress.1"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/debian/man/podofoxmp.1"
    )
endif()

