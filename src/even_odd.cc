#include <iostream>
#include <limits>

int main() {
    int num{};

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << '\n';
        } else {
            break;
        }
    }

    if (num % 2 == 0) {
        std::cout << num << " is even." << '\n';
    } else {
        std::cout << num << " is odd." << '\n';
    }

    std::cout.clear();
    return 0;
}