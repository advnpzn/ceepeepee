#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec) {
    size_t n = vec.size();
    bool swapped;

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> vec{64, 34, 25, 12, 22, 11, 90};

    std::cout << "Before sorting: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }

    bubbleSort(vec);

    std::cout << "\nAfter sorting: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << '\n';

    std::cout.flush();
    return 0;
}