#pragma once

#include <memory>

#include "ParkingStrategy.h"
#include "NearestFirst.h"
#include "FarthestFirst.h"


class ParkingStrategyContext{
public:
    std::unique_ptr<ParkingStrategy> setParkingStrategy(std::string&& s){
        if(s == "NEAREST_FIRST"){
            return std::make_unique<NearestFirst>();
        }else if(s == "FARTHEST_FIRST"){
            return std::make_unique<FarthestFirst>();
        }
        return nullptr;
    }

};