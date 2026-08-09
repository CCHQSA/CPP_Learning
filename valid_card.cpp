#include <iostream>


std::string doubleNums(const std::string& number);
int addNums(const std::string &numbers);
int addOddNums(const std::string &numbers);
bool valid(int &num1, int &num2);

int main(){
  
  std::string number;

  std::cout << "Enter a credit card number: ";
  std::cin >> number;

  std::string doubled = doubleNums(number);
  int firstValid = addNums(doubled);
  int secondValid = addOddNums(number);
  bool isValid = valid(firstValid, secondValid);
  if (isValid) {
    std::cout << "Card is valid";
  }else{
    std::cout << "Card is invalid";
  }
  
}


std::string doubleNums(const std::string &number){
  std::string doubled;
  for(int i = number.length() - 1; i >= 0; i--){

    if((number.length() - 1 - i) % 2 == 1){
      std::string num = std::to_string((number[i] - '0') * 2);
      doubled.insert(0, num);
    }
  }
  return doubled;
}

int addNums(const std::string &numbers){
  int res = 0;
  for(int i = 0; i < numbers.length(); i++){
    res += (numbers[i] - '0');
  }
  return res;
}

int addOddNums(const std::string &numbers){
  int res = 0;
  for(int i = numbers.length() - 1; i >= 0; i--){
    if((numbers.length() - 1 - i) % 2 == 0){
      int num = (numbers[i] - '0');
      res += num;
    }
  }
  return res;
}

bool valid(int &num1, int &num2){
  if ((num1 + num2) % 10 == 0){
    return true; 
  }else{
    return false;
  } 

}