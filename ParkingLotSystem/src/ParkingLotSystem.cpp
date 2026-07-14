
#include "../include/ParkingLotSystem.h"
#include "../include/SpotManager.h"


Ticket ParkingLotSystem::park(Vehicle v){
    ParkingSpot& freeSpot = spotManager->findAvailableSpot(v);

    //temporarily
     Ticket t;
     return t;
}

void ParkingLotSystem::unpark(TicketId){

}