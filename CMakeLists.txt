cmake_minimum_required (VERSION 3.5)

project(chttp)

set(CMAKE_CXX_STANDARD 20)

FILE(GLOB_RECURSE Parser_Files ${PROJECT_SOURCE_DIR}/src/parsers/*.cpp)
FILE(GLOB_RECURSE Http_Files ${PROJECT_SOURCE_DIR}/src/http/*.cpp)
FILE(GLOB_RECURSE Util_Files ${PROJECT_SOURCE_DIR}/src/utils/*.cpp)
FILE(GLOB_RECURSE Core_Files ${PROJECT_SOURCE_DIR}/src/core/*.cpp)

include_directories(src/)
include_directories(include/)

add_library(Lib_For_Test ${Parser_Files} ${Util_Files} ${Http_Files} ${Core_Files})

add_executable(main main.cpp)
target_link_libraries(main Lib_For_Test)

# Add sub directories
add_subdirectory(test)
