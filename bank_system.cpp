#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Transaction {
    std::string name;
    double amount;
};

void showBalance(double balance);
void deposit(double& balance, std::vector<Transaction>& history, double& totalDeposits, int& numOfDeposits);
void withdraw(double& balance, std::vector<Transaction>& history, double& totalWithdraws, int& numOfWithdraws);
void showHistory(const std::vector<Transaction>& history);
void clearHistory(std::vector<Transaction>& history);
double findLargestTransaction(const std::vector<Transaction>& history);
void showStatistics(double& totalDeposits,double& totalWithdraws, int& numOfDeposits, int& numOfWithdraws, std::vector<Transaction>& history);


int main() {
    double balance = 0;
    double totalDeposits = 0;
    double totalWithdraws = 0;
    int numOfDeposits = 0;
    int numOfWithdraws = 0;
    double largestTransaction = 0;
    int choice = 0;
    std::vector<Transaction> history = {};

    do {
        std::cout << "\n--- BANKING SYSTEM ---" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. History" << std::endl;
        std::cout << "5. Clear History" << std::endl;
        std::cout << "6. Show Statistics" <<std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                deposit(balance, history, totalDeposits, numOfDeposits);
                showBalance(balance); 
                break;
            case 3:
                withdraw(balance, history, totalWithdraws, numOfWithdraws);
                showBalance(balance); 
                break;
            case 4:
                showHistory(history);
                break;
            case 5:
                clearHistory(history);
                break;
            case 6:
                showStatistics(totalDeposits, totalWithdraws, numOfDeposits, numOfWithdraws, history);
                break;
            case 7:
                std::cout << "Exiting the program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while(choice != 7);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

void deposit(double& balance, std::vector<Transaction>& history, double& totalDeposits, int& numOfDeposits) {    double amount = 0;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    
    if (amount <= 0) {
        std::cout << "Invalid amount. Deposit failed." << std::endl;
        return;
    }

    balance += amount;
    totalDeposits += amount;
    Transaction transaction{"Deposit", amount};
    history.push_back(transaction);
    numOfDeposits++;
}

void withdraw(double& balance, std::vector<Transaction>& history, double& totalWithdraws, int& numOfWithdraws) {
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
    totalWithdraws += amount;
    Transaction transaction{"Withdrawal", amount};
    history.push_back(transaction); 
    numOfWithdraws++;
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

double findLargestTransaction(const std::vector<Transaction>& history) {
    if (history.empty()) {
        return 0.0;
    }

    double largest = history[0].amount;

    for (const Transaction& transaction : history) {
        if (transaction.amount > largest) {
            largest = transaction.amount;
        }
    }

    return largest;
}

void showStatistics(double& totalDeposits,double& totalWithdraws, int& numOfDeposits, int& numOfWithdraws, std::vector<Transaction>& history){
    std::cout<<"--- Statistics ---" <<"\n";
    std::cout<<"Total deposited: $" << totalDeposits <<std::endl;
    std::cout<<"Total withdrawn: $" << totalWithdraws <<std::endl;
    std::cout<<"Number of deposits: " <<numOfDeposits <<std::endl;
    std::cout<<"Number of withdrawals: " <<numOfWithdraws <<std::endl;
    std::cout<<"Largest transaction: " <<findLargestTransaction(history) <<std::endl;
    std::cout<<"------------------" <<std::endl;
}