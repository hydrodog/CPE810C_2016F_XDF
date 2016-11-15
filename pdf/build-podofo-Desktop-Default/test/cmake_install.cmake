# Install script for directory: /home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/test

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
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/ContentParser/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/CreationTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/FilterTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/FormTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/LargeTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/ObjectParserTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/ParserTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/SignatureTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/TokenizerTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/VariantTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/WatermarkTest/cmake_install.cmake")
  include("/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/test/unit/cmake_install.cmake")

endif()
