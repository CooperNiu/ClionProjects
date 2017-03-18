//
// Created by Cooper on 01/03/2017.
//

#ifndef TICKETMACHINE_TICKETMACHINE_H
#define TICKETMACHINE_TICKETMACHINE_H


class TicketMachine {
public:
    TicketMachine();
    virtual ~TicketMachine();

    void showPromt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();

private:
    const int PRICE = 10;
    int balance;
    int total;
};


#endif //TICKETMACHINE_TICKETMACHINE_H
