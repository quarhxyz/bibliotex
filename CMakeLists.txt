cmake_minimum_required(VERSION 3.10)
project(bibliotex)
set(SOURCE main.cpp library.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})