cmake_minimum_required(VERSION 3.5)

project(ParkingLotSystem CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(
    ParkingLot
    src/main.cpp
    src/ParkingLotSystem.cpp
    src/ParkingFloor.cpp
    src/ParkingStrategy.cpp
    src/SpotManager.cpp
    src/TicketManager.cpp
    src/ParkingSpot.cpp
    )

