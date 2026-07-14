#include "../include/SpotManager.h"

ParkingSpot& SpotManager::findAvailableSpot(Vehicle v){
        ParkingSpot&  freeSpot = freeSpots[v.type].front();
        freeSpots[v.type].pop();
        return freeSpot;
    }

void SpotManager::makeSpotAvailable(){
        
    }