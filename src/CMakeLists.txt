add_library(drone drone.cpp)
add_library(Dronenav::Drone ALIAS drone)
add_library(world world.cpp)
add_library(Dronenav::World ALIAS world)
