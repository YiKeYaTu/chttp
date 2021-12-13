cmake_minimum_required (VERSION 3.5)

project(chttp)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB Parser_Files ${PROJECT_SOURCE_DIR}/src/parsers/*.cpp)
FILE(GLOB Http_Files ${PROJECT_SOURCE_DIR}/src/http/*.cpp)
FILE(GLOB Util_Files ${PROJECT_SOURCE_DIR}/src/utils/*.cpp)

include_directories(src/)
include_directories(include/)

add_library(parser ${Parser_Files} ${Util_Files})
#target_include_directories(parser
#        PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(http ${Http_Files})
#target_include_directories(http
#        PUBLIC ${PROJECT_SOURCE_DIR}/include)

#add_executable(main src/main.cpp)
#target_include_directories(main
#        PUBLIC ${PROJECT_SOURCE_DIR}/include)
#target_link_libraries(main parser http)

# Add sub directories
add_subdirectory(test)
