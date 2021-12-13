cmake_minimum_required (VERSION 3.5)

project(chttp)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB Parser_Files ${PROJECT_SOURCE_DIR}/src/parsers/*.cpp)

add_library(parsers ${Parser_Files})
target_include_directories(parsers
        PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
target_include_directories(main
        PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(main parsers)

# Add sub directories
add_subdirectory(test)
