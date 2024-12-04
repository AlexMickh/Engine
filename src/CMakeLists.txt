cmake_minimum_required(VERSION 3.0.0)

project(src)

set(SOURCE_LIB glad.c)

add_library(src STATIC ${SOURCE_LIB})