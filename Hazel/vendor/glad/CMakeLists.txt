cmake_minimum_required(VERSION 3.21.4)
project(glad)

add_library(${PROJECT_NAME} include/glad/glad.h src/glad.c)

target_include_directories(${PROJECT_NAME} PRIVATE include)
