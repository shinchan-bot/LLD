#include "../include/SpotManager.h"

#include "../include/ParkingStrategyContext.h"


ParkingSpot& SpotManager::findAvailableSpot(Vehicle v){
    return parkingMethod->findAvailableSpot(v, freeSpots);
}

void SpotManager::releaseSpot(){

}

void SpotManager::setParkingContext(std::string&& s ){
    ParkingStrategyContext context;
    parkingMethod = context.setParkingStrategy("NEAREST_FIRST");
}