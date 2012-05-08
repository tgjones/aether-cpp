# needed packages
#include_directories(${ZLIB_INCLUDE_DIR})

# SET LIBNAME
set(PNG_LIB_NAME png)

# OUR SOURCES
set(libpng_public_hdrs
  png.h
  pngconf.h
)
set(libpng_sources
  ${libpng_public_hdrs}
  png.c
  pngerror.c
  pngget.c
  pngmem.c
  pngpread.c
  pngread.c
  pngrio.c
  pngrtran.c
  pngrutil.c
  pngset.c
  pngtrans.c
  pngwio.c
  pngwrite.c
  pngwtran.c
  pngwutil.c
)
# SOME NEEDED DEFINITIONS

add_definitions(-DPNG_CONFIGURE_LIBPNG)

# NOW BUILD OUR TARGET
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${ZLIB_INCLUDE_DIR})

# does not work without changing name
add_library(${PNG_LIB_NAME} ${libpng_sources})
target_link_libraries(${PNG_LIB_NAME} ${ZLIB_LIBRARY})