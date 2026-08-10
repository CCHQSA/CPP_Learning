#include <iostream>
#include <string>

int getDigits(const int number);
int sumEven(const std::string cardNumber);
int sumOdd(const std::string cardNumber);

int main(){
    std::string cardNumber;

    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    int result = sumEven(cardNumber) + sumOdd(cardNumber);
    
    if (result % 10 == 0){
        std::cout << "Card is valid\n";
    } else {
        std::cout << "Card is invalid\n";
    }
  
    return 0;
}

int getDigits(const int number){
    return number % 10 + (number / 10 % 10);
}

int sumEven(const std::string cardNumber){
    int res = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        res += getDigits((cardNumber[i] - '0') * 2);
    }
    return res;
}

int sumOdd(const std::string cardNumber){
    int res = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        res += cardNumber[i] - '0';
    }
    return res;
}
