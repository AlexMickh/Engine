cmake_minimum_required(VERSION 3.0.0)

project(engine VERSION 0.0.1)

set(SOURCE_EXE src/main.cpp)

include_directories(src shapes utils two_d) # name of the projects

add_executable(engine ${SOURCE_EXE})

add_subdirectory(src) # name of the directory
add_subdirectory(src/modules/two_d/shapes)
add_subdirectory(src/modules/utils)
add_subdirectory(src/modules/two_d)

target_link_libraries(engine glfw src shapes utils two_d)