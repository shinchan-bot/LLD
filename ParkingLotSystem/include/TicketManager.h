#pragma once

#include <unordered_map>

#include "Ticket.h"

class TicketManager{
public:
    void generateTicket();
    void closeTicket();

private:
    std::unordered_map<TicketId, std::unique_ptr<Ticket>> _Tickets;

};