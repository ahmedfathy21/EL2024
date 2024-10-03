#include <cassert>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <vector>


int main(){
int x = 10;
int y = 20;
auto f = [&x,y](int a,int b)mutable{
x = 20;
y = 10;
std::cout<<x<<std::endl;
std::cout<<y<<std::endl;
 return (a + b);
};
std::cout<<x<<std::endl;
std::cout<<f(10,20)<<std::endl;
std::cout<<y<<std::endl;
    return 0;
}