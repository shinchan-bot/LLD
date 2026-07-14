#include "../include/FarthestFirst.h"

ParkingSpot& FarthestFirst::findAvailableSpot(Vehicle v, 
    std::unordered_map<SpaceType, std::queue<ParkingSpot>>& freeSpots){
    ParkingSpot&  freeSpot = freeSpots[v.type].front();
    freeSpots[v.type].pop();
    return freeSpot;
    //use set queue later
}