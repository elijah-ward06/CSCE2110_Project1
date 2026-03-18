#ifndef TICKETS_HPP
#define TICKETS_HPP

#include "ticket.hpp"

class TicketNode{
    public:
    Ticket ticket;
    TicketNode* next;
    TicketNode* previous;

    TicketNode();
    ~TicketNode();
};

class Tickets{
    private:
        TicketNode* head;
        TicketNode* tail;
        int size;

    public:

    Tickets();
    Tickets(TicketNode* n);
    ~Tickets();

    void Insert(Ticket t);

    int getSize();
        
};


#endif