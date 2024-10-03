#include <iostream>
#include <cstring>
namespace  io = std;
class Data {
private:
    char *str;
    int size;

public:
    // Default constructor
    Data() : str(nullptr), size(0) {
        io::cout << "Default constructor" << std::endl;
    }

    // Parameterized constructor
    Data(const char* input_str) {
        io::cout << "Parameterized constructor" << std::endl;
        size = std::strlen(input_str); // get the size of the input string
        str = new char[size + 1]; // allocate memory for the string including null terminator
        io::strcpy(str, input_str); // copy the string
    }

    // Copy constructor (Deep copy)
    Data(const Data& copy) {
        io::cout << "Copy constructor" << std::endl;
        size = copy.size;
        str = new char[size + 1]; // allocate memory for the copied string
        io::strcpy(str, copy.str); // copy the string contents
    }

    // Destructor
    ~Data() {
        delete[] str; // free allocated memory
        io::cout << "Destructor" << std::endl;
    }

    // A method to print the string
    void fun() const {
        if (str) {
            io::cout << str << std::endl;
        } else {
            io::cout << "Empty" << std::endl;
        }
    }

    // A method to change the first character of the string
    void set_Char(char value) {
        if (str) {
            str[0] = value;
        }
    }
};

// A function to return a Data object
Data Get_Obj() {
    Data temp("Temporary");
    return temp;
}

int main() {
    char array[] = "Hello";

    // Create a Data object using the parameterized constructor
    Data mydata(array);

    // Call fun() to print the content of mydata
    mydata.fun(); // Should print "Hello"

    // Create a copy of mydata (calls copy constructor)
    Data mydata3(mydata);

    // Modify the copy and check that mydata is unaffected
    mydata3.set_Char('A'); // Changes the first character of mydata3

    // Print both to verify deep copy
    mydata.fun(); // Should print "Hello"
    mydata3.fun(); // Should print "Aello"
int x;
( x = 5) = 6;
std::cout<<x;
    return 0;
}
