#include <iostream>
#include <string>

int main() {
    std::string name{};
    std::cout << "Enter your name: ";
    std::cin >> name;

    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age << '.'
              << std::endl;

    return 0;
}