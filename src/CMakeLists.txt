add_definitions (-I"${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/png++-0.2.5")
add_definitions (-I"${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/libpng-1.2.49")

# Create variables for each set of source files
set (Cameras_SOURCES
  Cameras/Camera.cpp
  Cameras/OrthographicCamera.cpp
  Cameras/PinholeCamera.cpp
  Cameras/ProjectionCamera.cpp)

set (Math_SOURCES
  Math/Color.cpp
  Math/Matrix3D.cpp
  Math/Normal3D.cpp
  Math/Point3D.cpp
  Math/Point4D.cpp
  Math/Vector3D.cpp
  Math/Viewport3D.cpp)

set (Sampling_SOURCES
  Sampling/RegularSampler.cpp
  Sampling/Sample.cpp
  Sampling/Sampler.cpp)

set (Shapes_SOURCES
  Shapes/Plane.cpp
  Shapes/Sphere.cpp)

set (Root_SOURCES
  Aether.cpp
  Film.cpp
  InMemoryFilm.cpp
  Scene.cpp)

set (Aether_SOURCES
  ${Cameras_SOURCES}
  ${Math_SOURCES}
  ${Sampling_SOURCES}
  ${Shapes_SOURCES}
  ${Root_SOURCES})

# Add library called "aether" - this will be used by both the main executable
# and the tests
add_library (aether ${Aether_SOURCES})

# Add executable called "aether" that uses the aether library
add_executable (aether-bin main.cpp)
set_target_properties (aether-bin PROPERTIES OUTPUT_NAME aether)

target_link_libraries (aether-bin aether)
target_link_libraries (aether-bin z)
target_link_libraries (aether-bin png)
target_link_libraries (aether-bin c++)
