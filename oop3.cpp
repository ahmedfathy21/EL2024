#include <iostream>
#include <cstring>

class Data {
private:
    char* str;
    int size;

public:
    // Default constructor
    Data() : str(nullptr), size(0) {
        std::cout << "Default Constructor is Called" << std::endl;
    }
    // Parameterized constructor
    Data(const char* input) {
        size = std::strlen(input);
        str = new char[size + 1];  // Allocate memory for the string
        std::strcpy(str, input);
        std::cout << "Parameterized Constructor is Called" << std::endl;
    }

    // Copy constructor
    Data(const Data& other) {
        size = other.size;
        str = new char[size + 1];  // Deep copy of the string
        std::strcpy(str, other.str);
        std::cout << "Copy Constructor is Called" << std::endl;
    }

    // Move constructor
    Data(Data&& other) noexcept {
        std::cout << "Move Constructor is Called" << std::endl;
        str = other.str;       // Transfer ownership of the resource
        size = other.size;
        other.str = nullptr;   // Set the source object's pointer to nullptr to avoid double deletion
        other.size = 0;        // Reset the size of the source object
    }

    // Destructor
    ~Data() {
        if (str) {
            delete[] str;  // Free the allocated memory
        }
        std::cout << "Destructor is Called" << std::endl;
    }

    void print() const {
        if (str != nullptr)
            std::cout << "Data: " << str << std::endl;
        else
            std::cout << "Data: nullptr" << std::endl;
    }
};

// Function that returns a temporary object
Data create_data() {
    Data temp("Temporary");
    return temp;  // This will trigger the move constructor
}
void fun(const int &x){}
int main() {
    Data d1("Hello");     // Calls parameterized constructor
    Data d2(d1);          // Calls copy constructor

    Data d3(create_data());  // Calls move constructor because create_data() returns a temporary (rvalue)

    d1.print();
    d2.print();
    d3.print();  // The temporary object has been "moved" to d3
fun(5);
   
    return 0;
}



