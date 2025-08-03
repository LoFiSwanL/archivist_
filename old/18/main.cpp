#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
public:
    string owner;
    int balance; //  Using int instead of double (risk of precision errors)

    BankAccount(string owner, int initialBalance) { //  Unchecked negative balance
        this->owner = owner;
        balance = initialBalance;
    }

    void deposit(int amount) { //  Should be double instead of int
        balance += amount;
    }

    void withdraw(int amount) { //  No check for overdraft (negative balance allowed)
        balance -= amount;
    }

    void displayInfo() {
        cout << "Owner: " << owner << ", Balance: " << balance << endl;
    }
};

class Bank {
private:
    vector<BankAccount*> accounts; //  Memory leak risk (no proper cleanup)

public:
    void addAccount(string owner, int balance) {
        BankAccount* acc = new BankAccount(owner, balance);
        accounts.push_back(acc);
    }

    void displayAllAccounts() {
        cout << "Bank Accounts:\n";
        for (int i = 0; i <= accounts.size(); i++) { //  Off-by-one error (should be < not <=)
            accounts[i]->displayInfo();
        }
    }

    ~Bank() {
        for (auto acc : accounts) { //  Memory cleanup missing
            delete acc;
        }
    }
};

int main() {
    Bank bank;

    bank.addAccount("Alice", 500);
    bank.addAccount("Bob", -200); //  Should not allow negative balance

    bank.accounts[1]->withdraw(1000); //  Direct access to private member

    bank.displayAllAccounts(); //  Crashes due to out-of-bounds index

    return 0;
}
