cmake_minimum_required(VERSION 3.3)
project(Project_Euler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${Project_Euler_SOURCE_DIR}/headers)

set(SOURCE_FILES
        source/main.cpp
        headers/utils.h source/utils.cpp
        headers/bignumber.h source/bignumber.cpp
        headers/problem1.h source/problem1.cpp
        headers/problem2.h source/problem2.cpp
        headers/problem3.h source/problem3.cpp
        headers/problem4.h source/problem4.cpp
        headers/problem5.h source/problem5.cpp
        headers/problem6.h source/problem6.cpp
        headers/problem7.h source/problem7.cpp
        headers/problem8.h source/problem8.cpp
        headers/problem9.h source/problem9.cpp
        headers/problem10.h source/problem10.cpp
        headers/problem11.h source/problem11.cpp
        headers/problem12.h source/problem12.cpp
        headers/problem13.h source/problem13.cpp
        headers/problem14.h source/problem14.cpp
        headers/problem15.h source/problem15.cpp
        headers/problem16.h source/problem16.cpp
        headers/problem17.h source/problem17.cpp
        headers/problem18.h source/problem18.cpp
        )

add_executable(Project_Euler ${SOURCE_FILES})