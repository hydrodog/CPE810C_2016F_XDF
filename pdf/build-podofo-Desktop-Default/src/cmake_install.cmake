# Install script for directory: /home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo" TYPE FILE FILES
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/podofo-base.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/podofo.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base" TYPE FILE FILES
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/podofo_config.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/Pdf3rdPtyForwardDecl.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfArray.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfCanvas.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfColor.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfCompilerCompat.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfCompilerCompatPrivate.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfContentsTokenizer.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfData.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfDataType.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfDate.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfDefines.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfDefinesPrivate.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfDictionary.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfEncoding.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfEncodingFactory.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfEncrypt.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfExtension.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfError.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfFileStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfFilter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfFiltersPrivate.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfImmediateWriter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfInputDevice.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfInputStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfLocale.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfMemStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfMemoryManagement.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfName.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfObject.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfObjectStreamParserObject.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfOutputDevice.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfOutputStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfParser.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfParserObject.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfRect.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfRefCountedBuffer.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfRefCountedInputDevice.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfReference.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfSigIncWriter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfString.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfTokenizer.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfVariant.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfVecObjects.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfVersion.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfWriter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfXRef.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfXRefStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/PdfXRefStreamParserObject.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/podofoapi.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base/util" TYPE FILE FILES
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/util/PdfMutex.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/util/PdfMutexImpl_noop.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/util/PdfMutexImpl_win32.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/util/PdfMutexImpl_pthread.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/base/util/PdfMutexWrapper.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/doc" TYPE FILE FILES
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfAcroForm.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfAction.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfAnnotation.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfCMapEncoding.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfContents.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfDestination.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfDifferenceEncoding.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfDocument.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfElement.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfEncodingObjectFactory.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfExtGState.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfField.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFileSpec.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFont.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontCID.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontCache.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontConfigWrapper.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontFactory.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontFactoryBase14Data.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontMetrics.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontMetricsBase14.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontMetricsFreetype.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontMetricsObject.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontSimple.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontTTFSubset.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontTrueType.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontType1.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontType3.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFontType1Base14.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfFunction.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfHintStream.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfIdentityEncoding.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfImage.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfInfo.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfMemDocument.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfNamesTree.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfOutlines.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfPage.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfPagesTree.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfPagesTreeCache.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfPainter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfPainterMM.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfShadingPattern.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfSigIncMemDocument.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfSigIncPainter.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfSigIncSignatureField.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfSignOutputDevice.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfSignatureField.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfStreamedDocument.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfTable.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfTilingPattern.h"
    "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/podofo/src/doc/PdfXObject.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/zchenpds/git/CPE810C_2016F_XDF/pdf/build-podofo-Desktop-Default/src/libpodofo.a")
endif()

