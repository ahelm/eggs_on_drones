## Add Catch2 for testing
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4)

FetchContent_MakeAvailable(Catch2)

add_executable(test_drone test_drone.cpp)
target_link_libraries(test_drone PRIVATE Catch2::Catch2 Dronenav::Drone)
add_executable(test_world test_world.cpp)
target_link_libraries(test_world PRIVATE Catch2::Catch2 Dronenav::World Dronenav::Drone)
add_executable(test_input test_input.cpp)
target_link_libraries(test_input PRIVATE Catch2::Catch2 Dronenav::Input)
