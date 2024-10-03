#include <iostream>
#include <cstring>
class Data {
private:
    int size;
public:
    char* str;
    // Default constructor
    Data() : str(nullptr), size(0) {
        std::cout << "Default Constructor is Called" << std::endl;
    };
    // Parameterized constructor
    Data(const char* input) {
        size = std::strlen(input);
        str = new char[size + 1];  // Allocate memory for the string
        std::strcpy(str, input);
        std::cout << "Parameterized Constructor is Called  " <<this<< std::endl;
    };
    // Copy constructor
    Data(const Data& other) {
        size = other.size;
        str = new char[size + 1];  // Deep copy of the string
        std::strcpy(str, other.str);
        std::cout << "Copy Constructor is Called" <<this<< std::endl;
    };
    // Move constructor
    Data(Data&& other) noexcept {
        std::cout << "Move Constructor is Called " << this<<std::endl;
        str = other.str;       // Transfer ownership of the resource
        size = other.size;
        other.str = nullptr;   // Set the source object's pointer to nullptr to avoid double deletion
        other.size = 0;        // Reset the size of the source object
    };
    //Move Assignment Operator
    Data &operator=(Data&& other){
       std::cout<<"Move Assignment Operator is Called"<<std::endl;
       if(this == &other){// check if the object is the same object
           return *this;
       }
        delete [] this->str;
        this->str = other.str;
        this->size = other.size;
        other.str = nullptr;
        other.size = 0;
        return *this;
    };
    void get_value(){
        std::cout<<str<<std::endl;
    }
    // Destructor
    ~Data() {
        if (str) {
            delete[] str;  // Free the allocated memory
        }
        std::cout << "Destructor is Called " <<this<< std::endl;
    };
};
Data create_data() {
     Data temp("Temporary");
    return temp;  // move temp << temp is rvalue
    
}

int main() {
    // Data  d0("Welcome"); // Parameterized Constructor is Called
    // Data d1("Hello"); // Parameterized Constructor is Called
    // Data &&/*RValue Ref*/d2((std::move(d1)/*Lvalue ref */));// Move Constructor is Called
    // Data  d3 = d1; // Copy Constructor is Called
    Data name("Ahmed");// Parameterized Constructor is Called
    // Data &&name0(std::move(name));// name0 is just an alias for name and name 
    // Data name2(name);// copy constructor copy its value to name2 and make name2 has its own copy of the value of name 
    Data sayed("Sayed");
    sayed = std::move(name);
    // sayed.get_value();
    // Data name3(std::move(name));// move constructor move its value to name3 and make name empty Change the ownership of the resource
    // std::cout<<name.str<<std::endl;//name is empty string now
    // std::cout<<name2.str<<std::endl;//name2 has the value of name
    // std::cout<<name3.str<<std::endl; //name3 has the value of name and the ownership of the resource
    // std::cout<<name0.str<<std::endl;// name0 is now empty like the name cause it is just an alias for name

    // if the move constructor is not defined the copy constructor will be called instead of the move constructor
    // 1- it is just about the priority of the constructor

    return 0;   
}
