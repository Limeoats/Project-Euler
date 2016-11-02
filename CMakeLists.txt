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

set(SOURCE_FILES
        src/main.cpp
        src/utils.cpp
        src/problem001.cpp src/problem002.cpp src/problem003.cpp src/problem004.cpp src/problem005.cpp
        src/problem006.cpp src/problem007.cpp src/problem008.cpp src/problem009.cpp src/problem010.cpp
        src/problem011.cpp src/problem012.cpp src/problem013.cpp src/problem014.cpp src/problem015.cpp
        src/problem016.cpp src/problem017.cpp src/problem018.cpp src/problem019.cpp src/problem020.cpp
        src/problem021.cpp src/problem022.cpp src/problem023.cpp src/problem024.cpp src/problem025.cpp
        src/problem026.cpp src/problem027.cpp src/problem028.cpp src/problem029.cpp src/problem030.cpp
        src/problem031.cpp src/problem032.cpp src/problem033.cpp src/problem034.cpp src/problem035.cpp
        src/problem036.cpp src/problem037.cpp src/problem038.cpp src/problem039.cpp src/problem040.cpp
        src/problem041.cpp src/problem042.cpp src/problem043.cpp src/problem044.cpp src/problem045.cpp
        src/problem046.cpp src/problem047.cpp src/problem048.cpp src/problem049.cpp src/problem050.cpp
        src/problem051.cpp src/problem052.cpp src/problem053.cpp src/problem054.cpp src/problem055.cpp
        src/problem056.cpp src/problem057.cpp src/problem058.cpp src/problem059.cpp
        )

add_executable(Project_Euler ${SOURCE_FILES})

include(FindPkgConfig)
find_package(BigNumber REQUIRED)
include_directories(${BIGNUMBER_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${BIGNUMBER_LIBRARY})