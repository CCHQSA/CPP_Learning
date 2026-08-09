#include <iostream>

int main(){
  std::string questions[] = {"1. What year was C++ created?: ",
                             "2. Who invented C++?: ",
                             "3. What is the predecessor of C++?: "
                            };

  std::string options[][4] = {
                              {"A.1969", "B. 1975", "C. 1985", "D. 1989"},
                              {"A. Guido van Rossum", "B. Bjarne Strostrup", "C. Random dude", "D. John Carmack"},
                              {"A. C", "B. C+", "C. C--", "D. Holy C"}
                              };

  char answerKey[] = {'C', 'B', 'A'};

  int size = sizeof(questions)/sizeof(questions[0]);
  char guess;
  int score = 0;
  
  for (int i = 0; i < size; i++){
    std::cout << questions[i] <<"\n";
    for (int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
        std::cout << options[i][j] <<"\n";
    }

    std::cin >> guess;
    guess = toupper(guess);
    
    if (guess == answerKey[i]){
      score++;
      std::cout<<"Correct"  <<"\n";
    }else{
      std::cout << "Wrong" << "\n";
      std::cout << "The answer is: " << answerKey[i] <<"\n";
    }

    
  }

  std::cout << "Result: " << (score * 100) / size << "%\n";

}  
