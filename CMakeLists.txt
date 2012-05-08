# The name of this project is "AETHER". CMakeLists files in this project can 
# refer to the root source directory of the project as ${AETHER_SOURCE_DIR} and 
# to the root binary directory of the project as ${AETHER_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.6) 
project (AETHER) 

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Build zlib and libpng
add_subdirectory (src/3rdParty/zlib-1.2.7)
add_subdirectory (src/3rdParty/libpng-1.5.10)

set (CMAKE_CXX_COMPILER clang++)

add_definitions (-std=c++11)
add_definitions (-stdlib=libc++)

set (AETHER_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# Recurse into the "src" and "tests" subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure. 
add_subdirectory (src) 
add_subdirectory (tests)
