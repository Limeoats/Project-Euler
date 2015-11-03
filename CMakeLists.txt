cmake_minimum_required(VERSION 3.3)
project(Project_Euler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(${Project_Euler_SOURCE_DIR}/headers)

set(SOURCE_FILES
        source/main.cc
        headers/problem1.h
        headers/problem10.h
        headers/problem11.h
        headers/problem12.h
        headers/problem13.h
        headers/problem14.h
        headers/problem2.h
        headers/problem3.h
        headers/problem4.h
        headers/problem5.h
        headers/problem6.h
        headers/problem7.h
        headers/problem8.h
        headers/problem9.h
        headers/problem16.h
        headers/utils.h headers/problem15.h headers/bignumber.h)

add_executable(Project_Euler ${SOURCE_FILES})