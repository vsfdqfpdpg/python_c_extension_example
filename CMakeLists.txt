cmake_minimum_required(VERSION 3.22)

project(happy)

include_directories("/usr/include/python3.10")

add_library(${PROJECT_NAME} SHARED "src/proxy.c")

