#include <iostream>

bool isLeapYear(const int& year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main() {
    int year{};
    std::cout << "Enter a year: ";
    std::cin >> year;

    if (isLeapYear(year)) {
        std::cout << year << " is a leap year." << '\n';
    } else {
        std::cout << year << " is not a leap year." << '\n';
    }

    std::cout.flush();
    return 0;
}