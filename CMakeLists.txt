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
        source/problem001.cpp
        source/problem002.cpp
        source/problem003.cpp
        source/problem004.cpp
        source/problem005.cpp
        source/problem006.cpp
        source/problem007.cpp
        source/problem008.cpp
        source/problem009.cpp
        source/problem010.cpp
        source/problem011.cpp
        source/problem012.cpp
        source/problem013.cpp
        source/problem014.cpp
        source/problem015.cpp
        source/problem016.cpp
        source/problem017.cpp
        source/problem018.cpp
        source/problem019.cpp
        source/problem020.cpp
        source/problem021.cpp
        source/problem022.cpp
        source/problem023.cpp
        source/problem024.cpp
        source/problem025.cpp
        source/problem026.cpp
        source/problem027.cpp
        source/problem028.cpp
        source/problem029.cpp
        source/problem030.cpp
        source/problem031.cpp
        source/problem032.cpp
        source/problem033.cpp
        source/problem034.cpp
        source/problem035.cpp
        source/problem036.cpp
        source/problem037.cpp
        source/problem038.cpp
        source/problem039.cpp
        source/problem040.cpp
        source/problem041.cpp
        source/problem042.cpp
        source/problem043.cpp
        source/problem044.cpp
        source/problem045.cpp
        source/problem046.cpp
        source/problem047.cpp
        source/problem048.cpp
        source/problem049.cpp
        source/problem050.cpp
        )

add_executable(Project_Euler ${SOURCE_FILES})