cmake_minimum_required(VERSION 2.6)

project(turing_machine)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wshadow -Wcast-qual -Wlogical-op -Wredundant-decls")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(src)
