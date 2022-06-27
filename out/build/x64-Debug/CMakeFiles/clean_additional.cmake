# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MySQL_TableWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MySQL_TableWidget_autogen.dir\\ParseCache.txt"
  "MySQL_TableWidget_autogen"
  )
endif()
