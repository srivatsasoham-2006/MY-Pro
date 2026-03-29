#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    double balance;
    int pin;

public:
    BankAccount() {
        loadFromFile();
    }

    void loadFromFile() {
        ifstream file("account.txt");
        if (file) {
            file >> balance >> pin;
        } else {
            // Default values if file doesn't exist
            balance = 1000.0;
            pin = 1234;
        }
        file.close();
    }

    void saveToFile() {
        ofstream file("account.txt");
        file << balance << " " << pin;
        file.close();
    }

    bool authenticate() {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            return true;
        } else {
            cout << "Incorrect PIN!\n";
            return false;
        }
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }

        balance += amount;
        saveToFile();
        cout << "Deposit successful!\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amount;
        saveToFile();
        cout << "Withdrawal successful!\n";
    }

    void changePin() {
        int newPin;
        cout << "Enter new PIN: ";
        cin >> newPin;

        if (newPin < 1000 || newPin > 9999) {
            cout << "PIN must be 4 digits!\n";
            return;
        }

        pin = newPin;
        saveToFile();
        cout << "PIN changed successfully!\n";
    }
};

void showMenu() {
    cout << "\n===== ATM MENU =====\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Change PIN\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    BankAccount account;

    if (!account.authenticate()) {
        return 0;
    }

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                account.checkBalance();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.changePin();
                break;
            case 5:
                cout << "Thank you for using ATM!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
