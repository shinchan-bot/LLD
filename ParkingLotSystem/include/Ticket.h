#pragma once

#include "Vehicle.h"
#include "ParkingSpot.h"

using TicketId = int;

struct Ticket{
    TicketId id;
    int entryTime;
    int exitTime;
    Vehicle* vehicle;
    ParkingSpot* spot;
};