#pragma once

#include <unordered_map>
#include <queue>
#include <vector>

#include "ParkingSpot.h"
#include "ParkingStrategy.h"
#include "ParkingFloor.h"
#include "Types.h"
#include "Vehicle.h"



class SpotManager{
public:
    SpotManager(std::vector<ParkingFloor> floors){
        int n = floors.size();
        for(int i=0; i<n; i++){
            for(int j =0; j<floors[i].parkingSpots.size(); j++){
                ParkingSpot& spot = floors[i].parkingSpots[j];
                freeSpots[spot.type].push(spot);
            }
        }
    }

    ParkingSpot& findAvailableSpot(Vehicle v);

    void makeSpotAvailable();

private:
    std::unordered_map<SpaceType, std::queue<ParkingSpot>> freeSpots;

    
};