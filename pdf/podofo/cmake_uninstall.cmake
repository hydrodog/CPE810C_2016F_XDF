IF(NOT EXISTS "/Users/yingtinghuang/Downloads/localpdf/pdf/podofo/install_manifest.txt")
  MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/Users/yingtinghuang/Downloads/localpdf/pdf/podofo/install_manifest.txt\"")
ENDIF(NOT EXISTS "/Users/yingtinghuang/Downloads/localpdf/pdf/podofo/install_manifest.txt")

FILE(READ "/Users/yingtinghuang/Downloads/localpdf/pdf/podofo/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
  MESSAGE(STATUS "Uninstalling \"${file}\"")
  IF(NOT EXISTS "${file}")
    MESSAGE(FATAL_ERROR "File \"${file}\" does not exists.")
  ENDIF(NOT EXISTS "${file}")
  EXEC_PROGRAM("/usr/local/Cellar/cmake/3.6.3/bin/cmake" ARGS "-E remove \"${file}\""
    OUTPUT_VARIABLE rm_out
    RETURN_VARIABLE rm_retval)
  IF("${rm_retval}" GREATER 0)
    MESSAGE(FATAL_ERROR "Problem when removing \"${file}\"")
  ENDIF("${rm_retval}" GREATER 0)
ENDFOREACH(file)
