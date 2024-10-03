#include <cstddef>
#include <iostream>
void fun(){
std::cout<<"Hello"<<std::endl;

}
int main(){
    void (*prtfun)() =fun;
    prtfun();
    /*
int *ptr = new int(5);
std::cout<<*ptr<<std::endl;
delete ptr;
ptr =nullptr;
std::cout<<*ptr<<std::endl;
    */
return  0;
}