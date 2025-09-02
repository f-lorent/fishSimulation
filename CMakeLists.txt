cmake_minimum_required(VERSION 4.0)
project(FishSimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(FishSimulation main.cpp
        creature/fish/Fish.cpp
        creature/fish/Fish.h
        creature/position/Position.cpp
        creature/position/Position.h
        interface/Interface.cpp
        interface/Interface.h
        World/World.cpp
        World/World.h
        creature/velocity/Velocity.cpp
        creature/velocity/Velocity.h
        vector/Vector2d.cpp
        vector/Vector2d.h
        config.h
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(FishSimulation PRIVATE sfml-graphics sfml-window sfml-system)

