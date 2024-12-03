cmake_minimum_required(VERSION 3.0.0)

project(engine VERSION 0.0.1)

add_executable(engine src/main.cpp src/glad.h src/glad.c)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
target_link_libraries(engine glfw)