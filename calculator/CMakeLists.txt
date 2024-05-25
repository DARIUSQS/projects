cmake_minimum_required(VERSION 3.13)
project(ccalc)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES *.cpp)
file(GLOB INCLUDE_FILES *.h)

add_executable(ccalc ${SRC_FILES} ${INCLUDE_FILES})
