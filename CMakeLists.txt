cmake_minimum_required(VERSION 3.5)
project(dronenav CXX)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
set_target_properties(
    ${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(
        ${CMAKE_PROJECT_NAME} PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()

Include(FetchContent)

## Add Catch2 for testing
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4)

FetchContent_MakeAvailable(Catch2)
