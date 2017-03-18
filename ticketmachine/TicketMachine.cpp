//
// Created by Cooper on 01/03/2017.
//

#include "TicketMachine.h"

#include <iostream>
using namespace std;

TicketMachine::TicketMachine() {

}

TicketMachine::~TicketMachine() {

}

void TicketMachine::showPromt() {
    cout<<"something";
}

void TicketMachine::insertMoney(int money) {
    balance += money;
}

void TicketMachine::showBalance() {
    cout<<"show balance";
}

void TicketMachine::printTicket() {

}

void TicketMachine::showTotal() {

}
