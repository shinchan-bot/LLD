#pragma once

#include <unordered_map>
#include <queue>

#include "ParkingStrategy.h"
#include "ParkingSpot.h"



class FarthestFirst: public ParkingStrategy{
    ParkingSpot& findAvailableSpot(Vehicle v, 
    std::unordered_map<SpaceType, std::queue<ParkingSpot>>& freeSpots);
};