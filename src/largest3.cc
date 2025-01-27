#include <iostream>

int max(const int& a, const int& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int a{5};
    int b{20};
    int c{15};

    std::cout << "Largest of (" << a << ", " << b << ", " << c << ") is "
              << max(a, max(b, c)) << std::endl;

    return 0;
}