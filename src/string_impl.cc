#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ostream>

class string {
   private:
    char* data_;       // pointer to character data
    size_t length_;    // lenght of the string without null terminator
    size_t capacity_;  // allocated size of the string buffer

    void reallocate(size_t new_cap);

   public:
    string();
    string(const char* str);
    string(const string& other);      // copy constructor
    string(string&& other) noexcept;  // move constructor

    ~string();  // destructor

    // Assignment operators
    string& operator=(const string& other);      // copy assignment operator
    string& operator=(string&& other) noexcept;  // move assignment operator
    string& operator=(const char* str);          // assignment from C-string

    // Element access
    char& at(size_t pos);
    const char& at(size_t pos) const;

    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;

    char& front();
    const char& front() const;

    char& back();
    const char& back() const;

    const char* c_str() const;
    const char* data() const;

    // Capacity
    bool empty() const;
    size_t size() const;
    size_t length() const;
    size_t capacity() const;
    void reserve(size_t new_cap);
    void shrink_to_fit();

    // Operations
    void clear();
    string& append(const string& str);
    string& append(const char* str);
    string& operator+=(const string& str);
    string& operator+=(const char* str);
    void push_back(char c);
    void pop_back();

    // string operations
    int compare(const string& other) const;
    string substr(size_t pos, size_t len) const;

    static const size_t npos = -1;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const string& str);
    friend string operator+(const string& lhs, const string& rhs);
};

string::string() : data_(nullptr), length_(0), capacity_(0) {
    reallocate(1);
    data_[0] = '\0';
}

string::string(const char* str) : data_(nullptr), length_(0), capacity_(0) {
    if (str) {
        length_ = strlen(str);
        reallocate(length_ + 1);
        strcpy(data_, str);
    } else {
        reallocate(1);
        data_[0] = '\0';
    }
}

string::string(const string& other)
    : data_(nullptr), length_(other.length_), capacity_(other.capacity_) {
    reallocate(capacity_);
    strcpy(data_, other.data_);
}

string::string(string&& other) noexcept
    : data_(other.data_), length_(other.length_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.length_ = 0;
    other.capacity_ = 0;
}

string::~string() { delete[] data_; }

void string::reallocate(size_t new_cap) {
    if (new_cap > capacity_) {
        char* new_data = new char[new_cap];
        if (data_) {
            strcpy(new_data, data_);
            delete[] data_;
        }
        data_ = new_data;
        capacity_ = new_cap;
    }
}

void string::reserve(size_t new_cap) {
    if (new_cap > capacity_) {
        reallocate(new_cap);
    }
}

void string::shrink_to_fit() {
    if (length_ < capacity_) {
        reallocate(length_ + 1);
    }
}

string& string::operator=(const string& other) {
    if (this != &other) {
        if (other.length_ + 1 > capacity_) {
            reallocate(other.length_ + 1);
        }
        strcpy(data_, other.data_);
        length_ = other.length_;
    }
    return *this;
}

string& string::operator=(string&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        length_ = other.length_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.length_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

string& string::operator=(const char* str) {
    if (str) {
        size_t new_len = strlen(str);
        if (new_len + 1 > capacity_) {
            reallocate(new_len + 1);
        }
        strcpy(data_, str);
        length_ = new_len;

    } else {
        clear();
    }
    return *this;
}

char& string::at(size_t pos) {
    if (pos >= length_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[pos];
}

const char& string::at(size_t pos) const {
    if (pos >= length_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[pos];
}

char& string::operator[](size_t pos) { return data_[pos]; }

const char& string::operator[](size_t pos) const { return data_[pos]; }

char& string::front() { return data_[0]; }

const char& string::front() const { return data_[0]; }

char& string::back() { return data_[length_ - 1]; }

const char& string::back() const { return data_[length_ - 1]; }

const char* string::c_str() const { return data_; }

const char* string::data() const { return data_; }

bool string::empty() const { return length_ == 0; }

size_t string::size() const { return length_; }

size_t string::length() const { return length_; }

size_t string::capacity() const { return capacity_; }

void string::clear() {
    length_ = 0;
    data_[0] = '\0';
}

string& string::append(const string& str) {
    if (str.length_ == 0) {
        return *this;
    }

    if (length_ + str.length_ + 1 > capacity_) {
        reallocate(length_ + str.length_ + 1);
    }
    strcpy(data_ + length_, str.data_);
    length_ += str.length_;
    return *this;
}

#include <iostream>

int main() {
    string str1("Hello");
    string str2(" World");
    str1.append(str2);
    std::cout << str1.c_str() << std::endl;  // Output: Hello World
    return 0;
}
