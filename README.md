# Eggs on Drones

This repository contains a C++ app to help guide drones for a local tech savvy
chicken farmer to deliver eggs on time.

## Structure of the project

The project is structured in such away that it can be simply build and tries to
be modular in terms of the project layout. The project is structured as
following

```shell
.
├── app                   # Main application which provides drone positions
│  ├── CMakeLists.txt
│  └── main.cpp
├── CMakeLists.txt
├── data                  # Sample data input/output
│  ├── input.example
│  └── output.example
├── include               # Include files for main implementation
│  ├── drone.h
│  ├── input.h
│  └── world.h
├── README.md             # Readme for the example
├── src                   # Main program logic/implementation
│  ├── CMakeLists.txt
│  ├── drone.cpp
│  ├── input.cpp
│  └── world.cpp
└── tests                 # Tests for main implementations
   ├── CMakeLists.txt
   ├── test_drone.cpp
   ├── test_input.cpp
   └── test_world.cpp
```

## How to build the project

The project can be simply build using an out-of-source build by running the
following commands in the terminal

```shell
mkdir build
cmake -S . -B build
cmake --build build
```

Pay attention that the project uses a newer CMake version. The minimum
requirement for CMake `cmake_minimum_required(VERSION 3.11)` is `3.11`. The
reasoning for ths is the use of `FetchContent` which downloads
[Catch 2](https://github.com/catchorg/Catch2) and uses this for testing.

## How to run it

The app can be run by piping the example stored in `data/input.example`:

```shell
cat data/input.example | build/app/dronenav
```

which should return

```
1 3 N
5 1 E
```

and that corresponds to the output stored in `data/output.example`.

## How to run the tests

The tests are build using Catch2. They can be after the project has been build
by running the following executables

```shell
build/tests/test_drone
build/tests/test_input
build/tests/test_world
```
