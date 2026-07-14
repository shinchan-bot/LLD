#pragma once

using VehicleId = int;


enum class VehicleType{
    SMALL,
    MEDIUM,
    LARGE
};

struct Vehicle{
    VehicleId id;
    VehicleType type;
};