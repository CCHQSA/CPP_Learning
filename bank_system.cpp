#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct Transaction {
    std::string name;
    double amount;
};

void showBalance(double balance);
void deposit(double& balance, std::vector<Transaction>& history);
void withdraw(double& balance, std::vector<Transaction>& history);
void showHistory(const std::vector<Transaction>& history);
void clearHistory(std::vector<Transaction>& history);


int main() {
    double balance = 0;
    int choice = 0;
    std::vector<Transaction> history = {};

    do {
        std::cout << "\n--- BANKING SYSTEM ---" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. History" << std::endl;
        std::cout << "5. Clear History" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                deposit(balance, history);
                showBalance(balance); 
                break;
            case 3:
                withdraw(balance, history);
                showBalance(balance); 
                break;
            case 4:
                showHistory(history);
                break;
            case 5:
                clearHistory(history);
                break;
            case 6:
                std::cout << "Exiting the program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 6);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

void deposit(double& balance, std::vector<Transaction>& history) {
    Transaction transaction;
    double amount = 0;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    
    if (amount <= 0) {
        std::cout << "Invalid amount. Deposit failed." << std::endl;
        return;
    }

    balance += amount;

    transaction.name = "Deposit";
    transaction.amount = amount;
    history.push_back(transaction);
}

void withdraw(double& balance, std::vector<Transaction>& history) {
    Transaction transaction;
    double amount = 0;
    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid amount. Withdrawal failed." << std::endl;
        return;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        return;
    }

    balance -= amount;

    transaction.name = "Withdrawal";
    transaction.amount = amount;
    history.push_back(transaction); 
}

void showHistory(const std::vector<Transaction>& history) {
    std::cout << "\n--- TRANSACTION HISTORY ---\n";
    if (history.empty()) {
        std::cout << "No transactions yet.\n";
        return;
    }

    for(const Transaction& transaction : history) {
        std::cout << transaction.name << ": $" << std::fixed << std::setprecision(2) << transaction.amount << "\n";
    }
}

void clearHistory(std::vector<Transaction>& history) {
    if(!history.empty()) {
        history.clear();
        std::cout << "History has been deleted\n";
    } else {
        std::cout << "History already clear\n";
    }
}
