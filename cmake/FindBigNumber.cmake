#FindBigNumber.cmake
#By: Mark Guerra

set(FIND_BIGNUMBER_PATHS
        C:/Libs/BigNumber)


find_path(BIGNUMBER_INCLUDE_DIR bignumber.h
        PATH_SUFFIXES include
        PATHS ${FIND_BIGNUMBER_PATHS})

find_library(BIGNUMBER_LIBRARY
        NAMES bignumber
        PATH_SUFFIXES lib
        PATHS ${FIND_BIGNUMBER_PATHS})