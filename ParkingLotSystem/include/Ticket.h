#pragma once

#include "Vehicle.h"
#include "ParkingSpot.h"

using TicketId = int;

struct Ticket{
    TicketId it;
    int entryTime;
    int exitTime;
    Vehicle* vehicle;
    ParkingSpot* spot;
};