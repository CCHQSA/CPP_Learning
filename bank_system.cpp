#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>


void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    double balance = 0;
    int choice = 0;

    do {

        std::cout << "\n--- BANKING SYSTEM ---" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.clear(); 
        fflush(stdin);
        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance); 
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance); 
                break;
            case 4:
                std::cout << "Exiting the program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 4);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

double deposit() {
    double amount = 0;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    
    if (amount < 0) {
        std::cout << "Invalid amount. Deposit failed." << std::endl;
        return 0;
    }
    return amount;
}

double withdraw(double balance) {
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
    return amount;
}
