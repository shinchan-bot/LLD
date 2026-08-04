
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
    string _accountNumber;
};

class Session{
public:
    Card card;
    int amount;
    int pin;

};

class KeyPad{
private:

public:
    int readPIN(){
        cout<<"Enter PIN: ";
        int pin;
        cin>>pin;
        return pin;
    }

    int readAmount(){
        cout<<"Enter amount: ";
        int amount;
        cin>>amount;
        return amount;
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

};

class Display{
public:
    void showMenu(){
        cout<<"1 WithDrawl"<<endl;
        cout<<"2 Deposit"<<endl;
        cout<<"3 Ministatement"<<endl;
    }

    void show(std::string_view message, int balance){
        cout<<message<<endl;
        cout<<"Account Balance: "<<balance<<endl;
    }

};

class CardReader{
private:

public:
    Card readCard(){
        cout<<"Enter card number: ";
        Card c;
        cin>>c._cardNumber;
        c._accountNumber = "02394802";
        return c;
    }
};

class CashDispenser{
private:
    int totalCash = 1000000;
public:
    bool dispense(const unique_ptr<Session>& s){
        if(totalCash < s->amount){
            return false;
        }
        totalCash-=s->amount;
        return true;
    }
};

class BankingService{
public:
    string accountNumber = "02394802";
    int pin = 1234;
    int balance = 10000;
    int atmId = 0;
    ATMStatus atmStatus = ATMStatus::Ready;

    bool authenticate(const Session s){
        if(accountNumber == s.card._accountNumber && pin == s.pin){
            atmStatus = ATMStatus::Busy;
            return true;
        }
        return false;
    }

    bool debit(const unique_ptr<Session>& s){
        if(s->amount > balance){
            return false;
        }
        balance-=s->amount;
        atmStatus = ATMStatus::Ready;
        return true;
    }

    bool refund(const unique_ptr<Session>& s){
        balance+=s->amount;
        return true;
    }

    int getBalance(const unique_ptr<Session>& s){
        return balance;
    }

};

class Transaction{
public:
    virtual bool execute(const unique_ptr<Session>& s, BankingService& bs) = 0;

    // virtual void cancel() = 0;

    virtual ~Transaction() = default;

};

class Withdraw: public Transaction{
public:
    bool execute(const unique_ptr<Session>& s, BankingService& bs) override{

        if(bs.debit(s)){
            return true;
        }
        return false;
    }
};

class Deposit : public Transaction{
    bool execute(const unique_ptr<Session>& s, BankingService& bs) override{
        return true;
    }
};

class MiniStatement : public Transaction{
    bool execute(const unique_ptr<Session>& s, BankingService& bs) override{
        return true;
    }
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
        currentSession = make_unique<Session>();
        currentSession->card = cardReader.readCard();
        currentSession->pin = keyPad.readPIN();

        if(bankingService->authenticate(*currentSession)){
            display.showMenu();
            TransactionType t = keyPad.readTransaction();
            unique_ptr<Transaction> _myTransaction = transactionFactory.createTransaction(t);

            currentSession->amount = keyPad.readAmount();
            if(_myTransaction->execute(currentSession, *bankingService)){
                bool res = cashDispenser.dispense(currentSession);
                if(res){
                    int balance = bankingService->getBalance(currentSession);

                    display.show("Success", balance);
                    currentSession.reset();
                }
            }
        }
    }

private:
    int atmId;

    KeyPad keyPad;
    CardReader cardReader;
    CashDispenser cashDispenser;
    Display display;
    BankingService* bankingService;

    TransactionFactory transactionFactory;
    unique_ptr<Session> currentSession;

};


int main(){

    BankingService bank;
    ATM myATM(&bank);
    myATM.start();
    return 0;
}