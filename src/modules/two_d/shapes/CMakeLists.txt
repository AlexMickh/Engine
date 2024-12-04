cmake_minimum_required(VERSION 3.0.0)

project(shapes)

set(SOURCE_LIB triangle.cpp)

add_library(shapes STATIC ${SOURCE_LIB})