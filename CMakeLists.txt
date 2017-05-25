# CMakeLists.txt
# Mark Guerra
# 11/1/2015

cmake_minimum_required(VERSION 2.8)
project(Project_Euler)

if (WIN32)
    set(CPP_VERSION -std=gnu++14)
else()
    set(CPP_VERSION -std=c++14)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_VERSION}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

file(GLOB SOURCE_FILES src/*.cpp)

add_executable(Project_Euler ${SOURCE_FILES})

include(FindPkgConfig)
find_package(BigNumber REQUIRED)
include_directories(${BIGNUMBER_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${BIGNUMBER_LIBRARY})
