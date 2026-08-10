#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

void showBalance(double balance);
double deposit(std::vector<std::string>& history);
double withdraw(double balance, std::vector<std::string>& history);
void showHistory(const std::vector<std::string>& history);

int main() {
    double balance = 0;
    int choice = 0;
    std::vector<std::string> history = {};

    do {

        std::cout << "\n--- BANKING SYSTEM ---" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. History" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit(history);
                showBalance(balance); 
                break;
            case 3:
                balance -= withdraw(balance, history);
                showBalance(balance); 
                break;
            case 4:
                showHistory(history);
                break;
            case 5:
                std::cout << "Exiting the program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 5);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

double deposit(std::vector<std::string>& history) {
    double amount = 0;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    
    if (amount < 0) {
        std::cout << "Invalid amount. Deposit failed." << std::endl;
        return 0;
    }

    history.push_back("Deposit: +$" + std::to_string(amount));
    return amount;
}

double withdraw(double balance, std::vector<std::string>& history) {
    double amount = 0;
    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amount;

    if (amount < 0) {
        std::cout << "Invalid amount. Withdrawal failed." << std::endl;
        return 0;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        return 0;
    }

    history.push_back("Withdraw: -$" + std::to_string(amount));

    return amount;
}

void showHistory(const std::vector<std::string>& history) {
    std::cout << "\n--- TRANSACTION HISTORY ---\n";
    if (history.empty()) {
        std::cout << "No transactions yet.\n";
        return;
    }
    for (int i = 0; i < history.size(); i++) {
        std::cout << history[i] << std::endl;
    }
}
