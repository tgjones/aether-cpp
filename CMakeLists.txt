# The name of this project is "AETHER". CMakeLists files in this project can 
# refer to the root source directory of the project as ${AETHER_SOURCE_DIR} and 
# to the root binary directory of the project as ${AETHER_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.6) 
project (AETHER) 

set (CMAKE_CXX_COMPILER clang++)

add_definitions (-std=c++11)
add_definitions (-stdlib=libc++)

# Recurse into the "src" and "tests" subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure. 
add_subdirectory (src) 
add_subdirectory (tests)
