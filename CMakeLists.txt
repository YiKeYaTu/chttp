cmake_minimum_required (VERSION 3.5)

project(chttp)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB Parser_Files ${PROJECT_SOURCE_DIR}/src/parsers/*.cpp)
FILE(GLOB Http_Files ${PROJECT_SOURCE_DIR}/src/http/*.cpp)
FILE(GLOB Util_Files ${PROJECT_SOURCE_DIR}/src/utils/*.cpp)

include_directories(src/)
include_directories(include/)

add_library(parser ${Parser_Files} ${Util_Files})
add_library(http ${Http_Files})

add_executable(main main.cpp)
target_link_libraries(main parser http)

# Add sub directories
add_subdirectory(test)
