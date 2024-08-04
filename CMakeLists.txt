cmake_minimum_required(VERSION 3.15...3.29)
project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ version selection")  # or 11, 14, 17, 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # optional, ensure standard is supported
set(CMAKE_CXX_EXTENSIONS OFF)  # optional, keep compiler extensions off

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(pybind11)
# or find_package(pybind11 REQUIRED)

add_library(examples MODULE src/examples.cpp)

target_link_libraries(examples PRIVATE pybind11::module pybind11::lto pybind11::windows_extras)

pybind11_extension(examples)
if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    # Strip unnecessary sections of the binary on Linux/macOS
    pybind11_strip(examples)
endif()

set_target_properties(examples PROPERTIES CXX_VISIBILITY_PRESET "hidden"
                                         CUDA_VISIBILITY_PRESET "hidden")