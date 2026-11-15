# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.28.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

# Add mruby/c subdirectory
add_subdirectory(mrubyc)

target_sources(app PRIVATE src/main.c)

# Link mruby/c library
target_link_libraries(app PUBLIC mruby)

# Add mruby/c include directory to app
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/mrubyc)
