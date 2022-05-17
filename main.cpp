////
//// Created by chaari
////

#define max_accounts_number 100
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_NAME_LEN 40

class BankAccount {
protected:
    char name[MAX_NAME_LEN];
    int  account_number;
    double balance;
public:
    BankAccount ();
    BankAccount (char *);
    BankAccount (char *, int, double);
    void printSummary();
    double withdraw(double);
    void deposit(double);
    double getBalance();
    void setName(char *);
    void setAccount_number(int);
    void setbalance (double);
};


class saveBankAccount : public BankAccount{ //inheritance of BankAccount
protected:
    double interestRate;
    int noWithDraws ;
    int MAXnoWithDraws;
public:
    saveBankAccount (char *, int, double, double, int);
    void printSummary();
    double withdraw(double);
    void callInterest();
    void resetWithdraws ();
    void transfer(saveBankAccount &acc,double);
};

int main() {
// add code here
/**
 * The following lines of code does a sequence of operation on the Object Tom and eric.
 */
saveBankAccount tomAcc = saveBankAccount("Tom", 234567,2000,0.05,1);
tomAcc.deposit(1000);
tomAcc.printSummary();
tomAcc.withdraw(500);
tomAcc.printSummary();
tomAcc.withdraw(500);
tomAcc.printSummary();
tomAcc.getBalance();
tomAcc.resetWithdraws();
tomAcc.printSummary();
tomAcc.withdraw(500);
tomAcc.printSummary();
tomAcc.callInterest();
tomAcc.printSummary();
saveBankAccount ericACC = saveBankAccount("Eric", 23454,5000,0.04,1);
ericACC.printSummary();
ericACC.transfer(tomAcc,1000);
ericACC.printSummary();
tomAcc.printSummary();
return 0;
}

//**********************************************
// class BankAccount: methods
//**********************************************
BankAccount :: BankAccount () {
    name[0] = 0;
    account_number = 0;
    balance = 0.0;
}

BankAccount :: BankAccount (char *n) {
    strcpy(name, n);
    account_number = 0;
    balance = 0.0;
}

BankAccount :: BankAccount (char *n, int a_no, double bal) {
    strcpy(name, n);
    account_number = a_no;
    balance = bal;
}

void BankAccount :: printSummary() {
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "---------------------" << endl;
}

double BankAccount :: withdraw(double toWD) {
    if (balance-toWD > 0) {
        balance -= toWD;
    }
    else {
        cout << "!!!Sorry, not enough money!!!" << endl;
        return 0;
    }
    return toWD;
}

void BankAccount :: deposit(double toDep) {
    balance += toDep;
}

double BankAccount :: getBalance() {
    return balance;
}


void   BankAccount ::   setName(char *n) {
    strcpy(name, n);
}

void BankAccount ::setAccount_number(int a_no) {
    account_number = a_no;
}

void BankAccount ::setbalance(double bal) {
    balance = bal;
}

//**********************************************
// class saveBankAccount: methods
//**********************************************

//add your code here
/**
 * The following constructor inherits name , account number, and balance from BankAccount class
 * and sets news ones for saveBankAccount such as interest rate, maximum number of withdraws and sets
 * number of withdraws to 0.
 */
saveBankAccount::saveBankAccount(char *n, int a_no, double bal, double i_rate , int mno_withdraws)
:BankAccount(n, a_no, bal)
{
    interestRate = i_rate;
    MAXnoWithDraws = mno_withdraws;
    noWithDraws =0;


}

void saveBankAccount::printSummary() {
    /**
     * The following lines of code shows the summary of an account
     * such as name, account number, balance, interest rate, no withdraws,
     * and max number of withdraws.
     */

    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "Interest rate: " << interestRate << endl;
    cout << "Number of Withdraws: " << noWithDraws << endl;
    cout << "Max number of Withdraws: " << MAXnoWithDraws << endl;

    cout << "---------------------" << endl;

}

void saveBankAccount::callInterest() {
    /**
     * The following lines of code calculates the interest and shows
     * the new balance
     */
    balance += interestRate*balance;
    cout << "New Balance: " << balance << endl;
}

void saveBankAccount::resetWithdraws() {
    /**
     * The following lines of code just resets the number of withdraws
     * back to zero.
     */
    noWithDraws = 0;
}

void saveBankAccount::transfer(saveBankAccount &acc, double value) {
    /**
     * The following lines of code transfers money from one account to another
     * if balance is greater than the amount you want to transfer, then the transaction
     * follows through other wise you are prompted with an error message.
     */

    if((balance -=value)>0){
        acc.balance += value;
    }else{
        cout<<"transferring was unsuccessful"<<endl;

    }

}

double saveBankAccount::withdraw(double amount) {

    /**
     * The following lines of code is for withdrawing money out of your bank account
     * it checks if balance is greater than the amount you are withdrawing and also that
     * number of withdraws is less than or equal to maximum number of withdraws and also updates
     * the number of withdraws.
     */

    noWithDraws++;
    if ((balance - amount > 0) &&(noWithDraws<=MAXnoWithDraws)) {
        balance -= amount;
    } else if (balance - amount < 0) {
        cout << "You do not have enough money in your bank account" << endl;
    }
    if(noWithDraws>MAXnoWithDraws){
        cout<<"You have already reached maximum numbers of withdraws!"<<endl;
        noWithDraws--;
    }
    return amount;

}