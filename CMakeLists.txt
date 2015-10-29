cmake_minimum_required(VERSION 3.3)
project(Project_Euler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cc
    problem1.h
    problem10.h
    problem11.h
    problem12.h
    problem13.h
    problem14.h
    problem2.h
    problem3.h
    problem4.h
    problem5.h
    problem6.h
    problem7.h
    problem8.h
    problem9.h
    utils.h)

add_executable(Project_Euler ${SOURCE_FILES})