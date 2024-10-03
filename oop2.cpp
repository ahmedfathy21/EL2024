#include <iostream>
#include <string>

class Data {
private:
    std::string str;  // Use std::string instead of raw char*
    int age; 

public:
    // Default constructor
    Data() : str(""), age(0) {
        std::cout << "Default Constructor is Called" << std::endl;
    }

    // Parameterized constructor
    Data(std::string name, int age) : str(name), age(age) {
        std::cout << "Parameterized Constructor is Called" << std::endl;
    }

    // Function to print data
    void fun() {
        std::cout << str << "  " << age << std::endl;
    }

    // Destructor
    ~Data() {
        std::cout << "Default Destructor is Called" << std::endl;
    }

    // Copy constructor
    Data(const Data& copy) : str(copy.str), age(copy.age) {
        std::cout << "Copy Constructor is Called" << std::endl;
    }
     void set_value(std::string str,int age){
        this->str = str;
        this->age = age; 

     }
    
};

// Function that returns a temporary Data object
Data get_obj() {
    Data temp("Temp Name", 25);  // Temporary object with string and age
    return temp;
}

int &fun(){

  static int a = 20;
    return a;
}
int fun2(){

  static int a = 20;
    return a;
}

int main() {
// Data mydata("Ahmed",22);
// Data mydata2(mydata);
// mydata2.fun();
// mydata2.set_value("Hello", 20);
// mydata2.fun();
// mydata.fun();
const int x = 6;
// x + 1 = 8;// Lvalue required as left operand 
fun() = 20;
// fun2() = 30;// fun2() is a Lvalue not a ref 
int z = fun();
int a = 5; 
int &b{a};
b= 6;
const int &c{a};//COnst ref points to non const var
std::cout<<a<<std::endl;
// c =10; //Const ref Can not modify the value of the address which it ref to




    return 0;
}
