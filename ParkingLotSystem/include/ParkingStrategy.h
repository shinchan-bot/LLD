#pragma once

#include <memory>
#include <string>

#include <unordered_map>
#include <queue>
#include "Vehicle.h"
#include "ParkingSpot.h"



class ParkingStrategy{
public:
    virtual ParkingSpot& findAvailableSpot(Vehicle v, 
    std::unordered_map<SpaceType, std::queue<ParkingSpot>>& freeSpots) = 0;
   
    virtual ~ParkingStrategy() = default;
};