# CMakeList.txt : CMake project for jos-stam-fluid-sim, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("jos-stam-fluid-sim")

# Add source to this project's executable.
add_executable (jos-stam-fluid-sim "jos-stam-fluid-sim.cpp" "jos-stam-fluid-sim.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET jos-stam-fluid-sim PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
