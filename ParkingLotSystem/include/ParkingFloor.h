#pragma once

#include <vector>

#include "ParkingSpot.h"

class ParkingFloor{
public:

    ParkingFloor(int f){
        floor = f;
    }
    std::vector<ParkingSpot> parkingSpots;
private:
    int floor;

};