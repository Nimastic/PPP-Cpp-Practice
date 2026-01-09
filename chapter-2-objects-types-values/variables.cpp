#include <iostream>

int main() {
    std::cout << "Please enter your name and age: ";
    std::string first_name;
    int first_age;
    std::cin >> first_name >> first_age;
    std::cout << "Hello, " << first_name << "! You are " << first_age << " years old." << std::endl;
    return 0;
}