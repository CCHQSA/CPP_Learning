#include <iostream>
#include <string>
#include <ctime>

void greeting(int repeat, std::string name);

int main() {
    greeting(5, "Alice");
    return 0;
}

void greeting(int repeat, std::string name) {
    for(int i = 0; i < repeat; i++){
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}
