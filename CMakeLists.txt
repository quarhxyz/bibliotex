cmake_minimum_required(VERSION 3.10)
project(bibliotex)
set(SOURCE main.cpp commands.cpp functions.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
