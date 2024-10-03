#include <iostream>

class String {
private:
    int length;
    char* str;

public:
    // Constructor
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0';  // Null-terminate the string
    }

    // Copy Constructor
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = other.str[i];
        }
        str[length] = '\0';  // Null-terminate the string
    }

    // Move Constructor
    String(String&& other) noexcept {
        length = other.length;
        str = other.str;
        other.str = nullptr;
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Getter for length
    int getLength() const {
        return length;
    }

    // Getter for string
    const char* getString() const {
        return str;
    }

    // Setter for string
    void setString(const char* s) {
        delete[] str;
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0';  // Null-terminate the string
    }
};

// Overload << operator for easy printing
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.getString();
    return os;
}

int main() {
    String s("Hello, World!");
    std::cout << "Length: " << s.getLength() << std::endl;
    std::cout << "String: " << s << std::endl;

    s.setString("New String");
    std::cout << "Length: " << s.getLength() << std::endl;
    std::cout << "String: " << s << std::endl;

    return 0;
}