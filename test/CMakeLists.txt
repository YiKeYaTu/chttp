# Set the project name
project (test)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FILE(GLOB_RECURSE Test_Files "*.cpp")

add_executable(${PROJECT_NAME} ${Test_Files})

target_link_libraries(${PROJECT_NAME}
        parsers
        gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})