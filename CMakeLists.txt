cmake_minimum_required(VERSION 3.5)
project(
    Dronenav
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
endif()

include_directories(include)
add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(tests)
