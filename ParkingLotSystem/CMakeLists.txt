cmake_minimum_required(VERSION 3.10)

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
    src/NearestFirst.cpp
    src/FarthestFirst.cpp
    include/ParkingFloor.h
    include/ParkingLotSystem.h
    include/ParkingSpot.h
    include/ParkingStrategy.h
    include/ParkingStrategyContext.h
    include/PaymentStrategy.h
    include/PaymentStrategyContext.h
    include/SpotManager.h
    include/Ticket.h
    include/TicketManager.h
    include/Vehicle.h
    include/VehicleBasedPayment.h
    )

