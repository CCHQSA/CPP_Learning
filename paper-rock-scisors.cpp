#include <iostream>
#include<ctime>

char userChoice();
char computerChoice();
void showChoices(char choice);
void showWinner(char user, char computer);


int main(){
  srand((time(0)));
  bool playAgain = true;
  std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
  do{
  char user = userChoice();
  char computer = computerChoice();
  showChoices(user);
  showChoices(computer);
  showWinner(user, computer);
  std::cout << "Do you want to play again? (y/n): ";
  
  std::cout << "Play again? (y/n): ";
  char again;
  std::cin >> again;
  if(again == 'y' || again == 'Y'){
    playAgain = true;
  }else if(again == 'n' || again == 'N'){
    playAgain = false;
  }else{
    std::cout << "Invalid input. Exiting the game." << std::endl;
    playAgain = false;
  }
  }while(playAgain);

}

char computerChoice(){
  int randomNum = rand() % 3; 
  switch(randomNum){
    case 0: return 'r';
    case 1: return 'p';
    case 2: return 's';
  }
  return 'r';
}

char userChoice(){
  char choice;
  std::cout << "Enter your choice (r for rock, p for paper, s for scissors): ";
  std::cin >> choice;
  if(choice != 'r' && choice != 'p' && choice != 's'){
    std::cout << "Invalid choice. Please try again." << std::endl;
    return userChoice();
  }
  return choice;
}
void showChoices(char choice){
  switch(choice){
    case 'r': std::cout << "Rock" <<"\n";
              break;
    case 'p': std::cout << "Paper" <<"\n";
              break;
    case 's': std::cout << "Scissors" <<"\n";
              break;
  }
}

void showWinner(char user, char computer){
  if(user == computer){
    std::cout <<"Tie" << std::endl;
  }else if((user == 'r' && computer == 's') || (user == 'p' && computer == 'r') || (user == 's' && computer == 'p')){
    std::cout << "You win!" << std::endl;
  }else{
    std::cout << "Computer wins!" << std::endl;
  }
}