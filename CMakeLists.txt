# CMakeLists.txt
# Mark Guerra
# 11/1/2015

cmake_minimum_required(VERSION 3.3)
project(Project_Euler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${Project_Euler_SOURCE_DIR}/headers)

set(SOURCE_FILES
        source/main.cpp
        source/utils.cpp
        source/bignumber.cpp
        source/problem1.cpp
        source/problem2.cpp
        source/problem3.cpp
        source/problem4.cpp
        source/problem5.cpp
        source/problem6.cpp
        source/problem7.cpp
        source/problem8.cpp
        source/problem9.cpp
        source/problem10.cpp
        source/problem11.cpp
        source/problem12.cpp
        source/problem13.cpp
        source/problem14.cpp
        source/problem15.cpp
        source/problem16.cpp
        source/problem17.cpp
        source/problem18.cpp
        source/problem19.cpp
        source/problem20.cpp
        source/problem21.cpp
        source/problem22.cpp
        source/problem23.cpp
        source/problem24.cpp
        source/problem25.cpp
        source/problem26.cpp
        source/problem27.cpp
        source/problem28.cpp
        source/problem29.cpp
        source/problem30.cpp
        source/problem31.cpp
        source/problem32.cpp
        source/problem33.cpp
        source/problem34.cpp
        source/problem35.cpp
        source/problem36.cpp
        source/problem37.cpp
        source/problem38.cpp
        source/problem39.cpp
        source/problem40.cpp
        source/problem41.cpp
        source/problem42.cpp
        source/problem43.cpp
        source/problem44.cpp
        source/problem45.cpp
        source/problem46.cpp
        source/problem47.cpp
        source/problem48.cpp
        )

add_executable(Project_Euler ${SOURCE_FILES})