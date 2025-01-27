#include <iostream>

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a{5};
    int b{10};
    std::cout << "Before: " << a << " " << b << std::endl;
    swap(a, b);
    std::cout << "After: " << a << " " << b << std::endl;

    return 0;
}