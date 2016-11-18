# Install script for directory: /Users/Leigh/Desktop/localpdf/pdf/podofo/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo" TYPE FILE FILES
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/podofo-base.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/podofo.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base" TYPE FILE FILES
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/podofo_config.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/Pdf3rdPtyForwardDecl.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfArray.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfCanvas.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfColor.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfCompilerCompat.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfCompilerCompatPrivate.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfContentsTokenizer.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfData.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfDataType.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfDate.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfDefines.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfDefinesPrivate.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfDictionary.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfEncoding.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfEncodingFactory.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfEncrypt.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfExtension.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfError.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfFileStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfFilter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfFiltersPrivate.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfImmediateWriter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfInputDevice.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfInputStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfLocale.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfMemStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfMemoryManagement.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfName.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfObject.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfObjectStreamParserObject.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfOutputDevice.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfOutputStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfParser.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfParserObject.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfRect.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfRefCountedBuffer.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfRefCountedInputDevice.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfReference.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfSigIncWriter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfString.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfTokenizer.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfVariant.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfVecObjects.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfVersion.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfWriter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfXRef.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfXRefStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/PdfXRefStreamParserObject.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/podofoapi.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base/util" TYPE FILE FILES
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/util/PdfMutex.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/util/PdfMutexImpl_noop.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/util/PdfMutexImpl_win32.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/util/PdfMutexImpl_pthread.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/base/util/PdfMutexWrapper.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/doc" TYPE FILE FILES
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfAcroForm.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfAction.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfAnnotation.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfCMapEncoding.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfContents.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfDestination.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfDifferenceEncoding.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfDocument.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfElement.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfEncodingObjectFactory.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfExtGState.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfField.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFileSpec.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFont.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontCID.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontCache.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontConfigWrapper.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontFactory.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontFactoryBase14Data.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontMetrics.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontMetricsBase14.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontMetricsFreetype.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontMetricsObject.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontSimple.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontTTFSubset.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontTrueType.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontType1.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontType3.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFontType1Base14.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfFunction.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfHintStream.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfIdentityEncoding.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfImage.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfInfo.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfMemDocument.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfNamesTree.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfOutlines.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfPage.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfPagesTree.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfPagesTreeCache.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfPainter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfPainterMM.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfShadingPattern.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfSigIncMemDocument.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfSigIncPainter.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfSigIncSignatureField.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfSignOutputDevice.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfSignatureField.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfStreamedDocument.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfTable.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfTilingPattern.h"
    "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/doc/PdfXObject.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Leigh/Desktop/localpdf/pdf/podofo/src/libpodofo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.a")
  endif()
endif()

