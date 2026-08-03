
#include <iostream>
#include <memory>
#include <string>
using namespace std;

enum class ATMStatus{
    Ready,
    Busy
};

enum class TransactionType{
    Withdraw,
    Deposit,
    Ministatement,
    Invalid
};

class Card {
public:
    string _cardNumber;
};

class Session{
    Card card;
    int accountNumber;
    int amount;
};

class KeyPad{
private:
    std::string _pin;

public:
    void readPIN(){
        cout<<"Enter PIN: ";
        cin>>_pin;
    }

    TransactionType readTransaction(){
        cout<<"Enter Transaction: ";
        int x;
        cin>>x;
        if(x == 1) return TransactionType::Withdraw;
        else if(x == 2) return TransactionType::Deposit;
        else if(x == 3) return TransactionType::Ministatement;
        else return TransactionType::Invalid;
    }

    std::string getPIN() {
        return _pin;
    }

};

class Display{
public:
    void showMenu(){
        cout<<"1 WithDrawl"<<endl;
        cout<<"2 Deposit"<<endl;
        cout<<"3 Ministatement"<<endl;
    }

};

class CardReader{
private:
    Card _card;


public:
    void readCard(){
        cout<<"Enter card number: ";
        cin>>_card._cardNumber;
    }

    Card getCard(){
        return _card;
    }

};

class CashDispenser{

};

class BankingService{
public:
    int accountId = 0;
    int balance = 10000;
    int atmId = 0;
    ATMStatus atmStatus = ATMStatus::Ready;

};

class Transaction{

    
};

class Withdraw: public Transaction{

};

class Deposit : public Transaction{

};

class MiniStatement : public Transaction{

};

class TransactionFactory{
public:
    unique_ptr<Transaction> createTransaction(TransactionType t){
        if(t == TransactionType::Withdraw) return make_unique<Withdraw>();
        else if(t == TransactionType::Deposit) return make_unique<Deposit>();
        else if(t == TransactionType::Ministatement) return make_unique<MiniStatement>();
        else return nullptr;
    }
};

class ATM{
public:
    ATM(BankingService* service): bankingService(service){}

    void start() {
        bankingService->atmStatus = ATMStatus::Busy;
        cardReader.readCard();
        keyPad.readPIN();
        display.showMenu();
        TransactionType t = keyPad.readTransaction();
        // unique_ptr<Transaction> _myTransaction = 

    }

private:
    int atmId;

    KeyPad keyPad;
    CardReader cardReader;
    CashDispenser cashDispenser;
    Display display;
    BankingService* bankingService;

    std::unique_ptr<TransactionFactory> transactionFactory;
    std::unique_ptr<Session> currentSession;

};


int main(){

    BankingService bank;
    ATM myATM(&bank);
    myATM.start();
    return 0;
}