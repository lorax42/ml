cmake_minimum_required(VERSION 3.20)
file(GLOB src "src/*.c")
project(ml C)
add_executable(${PROJECT_NAME} ${src})

