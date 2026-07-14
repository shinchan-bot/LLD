#pragma once

#include "ParkingStrategy.h"
#include "ParkingSpot.h"
#include "SpotManager.h"


class NearestFirst: public ParkingStrategy{
    ParkingSpot& findAvailableSpot(Vehicle v, 
    std::unordered_map<SpaceType, std::queue<ParkingSpot>>& freeSpots);
};