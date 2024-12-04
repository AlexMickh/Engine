cmake_minimum_required(VERSION 3.0.0)

project(utils)

set(SOURCE_LIB readShader.cpp)

add_library(utils STATIC ${SOURCE_LIB})