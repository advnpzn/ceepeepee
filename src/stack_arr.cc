// stack based on dynamic arrays

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <print>
#include <stdexcept>
#include <utility>

template <typename T>
class Stack {
   private:
    std::unique_ptr<T[]> data;
    size_t capacity;
    size_t top_index;

   private:
    void resize(size_t new_capacity) {
        auto new_data = std::make_unique<T[]>(new_capacity);
        for (size_t i = 0; i < top_index; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = std::move(new_data);
        capacity = new_capacity;
    }

   public:
    explicit Stack(size_t initial_capacity = 10)
        : data(std::make_unique<T[]>(initial_capacity)),
          capacity(initial_capacity),
          top_index(0) {}

    Stack(std::initializer_list<T> init)
        : data(std::make_unique<T[]>(init.size())),
          capacity(init.size()),
          top_index(0) {
        std::copy(init.begin(), init.end(), data.get());
    }

    // push element onto stack
    void push(const T& value) {
        if (top_index == capacity) {
            resize(capacity * 2);
        }
        data[top_index++] = value;
    }

    // push with move semantics
    void push(T&& value) {
        if (top_index == capacity) {
            resize(capacity * 2);
        }
        data[top_index++] = std::move(value);
    }

    // emplace element directly on stack
    template <typename... Args>
    void emplace(Args&&... args) {
        if (top_index == capacity) {
            resize(capacity * 2);
        }
        data[top_index++] = T(std::forward<Args>(args)...);
    }

    // check empty or not
    bool emtpy() const noexcept { return top_index == 0; }

    // pop an element
    void pop() {
        if (emtpy()) {
            throw std::out_of_range("stack underflow");
        }
        --top_index;
    }

    // get top element
    T& top() {
        if (emtpy()) {
            throw std::out_of_range("stack is emtpy");
        }
        return data[top_index - 1];
    }

    const T& top() const {
        if (emtpy()) {
            throw std::out_of_range("stack is emtpy");
        }
        return data[top_index - 1];
    }

    // get current size
    size_t size() const noexcept { return top_index; }

    // get current capacity
    size_t get_capacity() const noexcept { return capacity; }
};

int main() {
    Stack<int> stack;
    stack.push(25);

    std::println("Top: {}\nSize: {}\nCapacity: {}", stack.top(), stack.size(),
                 stack.get_capacity());

    return 0;
}