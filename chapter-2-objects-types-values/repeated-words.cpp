#include <iostream>

int main() {
    int repeated_words = 0;
    std::string previous;
    std::string current;
    while (std::cin >> current) {
        if (previous == current) {
            std::cout << "repeated word: " << current << std::endl;
            repeated_words++;
        }
        previous = current;
    }
    std::cout << "number of repeated words: " << repeated_words << std::endl;
    return 0;
}