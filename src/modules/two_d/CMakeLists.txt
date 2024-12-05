cmake_minimum_required(VERSION 3.0.0)

project(two_d)

set(SOURCE_LIB vector2.cpp)

add_library(two_d STATIC ${SOURCE_LIB})