#include <iostream>

int main() {
    std::cout << "Please enter your name and age: \n";
    std::string name = "???";
    double age = 0;
    std::cin >> name >> age;
    std::cout << "Hello, " << name << " (age " << age * 12 << " months old)";
    return 0;
}

// by convention, reading of strings is terminated by whitespace