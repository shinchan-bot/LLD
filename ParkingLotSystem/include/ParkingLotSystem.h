#pragma once

#include <memory>

#include "ParkingFloor.h"
#include "Vehicle.h"
#include "TicketManager.h"
#include "SpotManager.h"
#include "Ticket.h"

class ParkingLotSystem{
public:
    ParkingLotSystem(){
        ticketManager = std::make_unique<TicketManager>();
        spotManager = std::make_unique<SpotManager>(floors);
    }
    Ticket park(Vehicle);
    void unpark(TicketId);

private:
    std::unique_ptr<TicketManager> ticketManager;
    std::unique_ptr<SpotManager> spotManager;
    std::vector<ParkingFloor> floors;
};