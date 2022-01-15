project(shibokensample)
cmake_minimum_required(VERSION 2.6)

# Generate Pure C++ Library
add_library(UniverseCpp SHARED
  src/icecream.cpp
  src/truck.cpp
)

# Load packages for Python bindings
find_package(PythonLibs 2.7 REQUIRED)
find_package(Shiboken 1.2.0 REQUIRED)
find_package(Qt4 4.5.0 REQUIRED)

# Set the name of auto generated files by shiboken
# into the variable Universe_SRC
set(Universe_SRC
  ${CMAKE_CURRENT_BINARY_DIR}/Universe/icecream_wrapper.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/Universe/truck_wrapper.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/Universe/universe_module_wrapper.cpp
)

# Add rules to generate python binding files
add_custom_command(
  OUTPUT ${Universe_SRC}
  COMMAND ${SHIBOKEN_BINARY} ${GENERATOR_EXTRA_FLAGS}
  ${CMAKE_SOURCE_DIR}/bindings.h
  --include-paths=${CMAKE_SOURCE_DIR}/src
  --typesystem-paths=""
  --output-directory=${CMAKE_CURRENT_BINARY_DIR}
  --license-file=${CMAKE_SOURCE_DIR}/src/licensecomment.txt
  ${CMAKE_SOURCE_DIR}/bindings.xml
  --api-version="0.0.0"
  --drop-type-entries=""
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
COMMENT "Running generator for ${module_name}...")

# Set header file locations
include_directories(
  ${CMAKE_SOURCE_DIR}/src
  ${PYTHON_INCLUDE_DIRS}
  ${SHIBOKEN_INCLUDE_DIR}
)
# Generate python bindings
add_library(Universe MODULE
  src/icecream.cpp
  src/truck.cpp
  ${Universe_SRC}
)
target_link_libraries(Universe ${SHIBOKEN_LIBRARY})
set_target_properties(Universe PROPERTIES PREFIX "")
