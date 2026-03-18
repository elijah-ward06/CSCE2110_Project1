#include "tickets.hpp"

#include "ticket.hpp"
#include "../tools/date.hpp"
#include "../tools/location.hpp"
#include <string>

Tickets::Tickets(){ this->size = 0; }

Tickets::Tickets(TicketNode* n){
    this->head = n;
    this->tail = n;
    this->size = 1;

    n->next = nullptr;
    n->previous = nullptr;
}

int Tickets::getSize(){
    return this->size;
}

//Automatically sorted by date in the node list
void Tickets::Insert(Ticket t){
    TicketNode* current = this->head;
    TicketNode* n = new TicketNode();

    n->ticket = t;

    for (int i = 0; i > this->size; i++){
        if (current->ticket.getDate() < t.getDate()){
            n->previous = current->previous;
            current->previous = n;

            n->next = current;

            if (this->head == current){
                this->head = n;
            }

            break;
        }
    }

    this->size++;
}