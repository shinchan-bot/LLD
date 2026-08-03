
#include <iostream>
#include <memory>

class Session{

};

class KeyPad{

};

class Display{

};

class CardReader{

};

class CashDispenser{

};

class BankingService{

};

class TransactionFactory{

};

class Transaction{

};

class Withdraw: public Transaction{

};

class Deposit : public Transaction{

};

class MiniStatement : public Transaction{

};

class ATM{

private:
    int atmId;

    KeyPad keyPad;
    CardReader cardReader;
    CashDispenser cashDispenser;
    Display display;
    BankingService* bankingService;

    std::unique_ptr<Session> currentSession;

};


int main(){
    return 0;
}