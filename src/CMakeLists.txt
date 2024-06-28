
set(LIBRARY_NAME "ulog")
set(LIBRARY_SOURCE_FILES
   ulogger.cpp
   base_logger.cpp)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PRIVATE
     ${CMAKE_SOURCE_DIR}/src)