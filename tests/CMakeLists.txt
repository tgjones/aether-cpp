# Allow test cpp files to #include source files directly
add_definitions (-iquote${AETHER_SOURCE_DIR})

# Allow igloo testing framework to locate its own files with <igloo/...>
add_definitions (-I${CMAKE_CURRENT_SOURCE_DIR})

set (Test_SOURCES
  PlaneTests.cpp
  RegularSamplerTests.cpp
  SphereTests.cpp
  Vector3DTests.cpp)

# Add executable called "aether_tests" that is built from the Aether source files,
# combined with the test source files. 
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found. 
add_executable (aether_tests
  main.cpp
  ${Aether_SOURCES}
  ${Test_SOURCES})

target_link_libraries (aether_tests aether)
target_link_libraries (aether_tests c++)

# Add test
#add_test (aether_tests ${AETHER_BINARY_DIR}/aether_tests)
