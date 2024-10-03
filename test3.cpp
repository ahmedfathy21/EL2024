#include <algorithm>
#include <future>
#include<iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
class Data{
private:
int real; 
float image;
public: 
Data(){std::cout<<"Default Constructor is called"<<std::endl;}
~Data(){std::cout<<"Default Distructor is called"<<std::endl;}
Data(int real,float image):real(real),image(image){std::cout<<"Valued Constructor is called"<<std::endl;}
friend std::ostream& operator<<(std::ostream& os, const Data& obj);
int operator+(int num){
   return this->real+num;
}
float operator+(float img){
    return this->image + img;
}
Data operator+(const Data &temp){
Data Result;
Result.real = this->real + temp.real;
Result.image = this->image + temp.image;
return Result;
}
void operator()(void){std::cout<<"Functor Called!"<<std::endl;}
int operator-(int Num){
return  this->real -Num;
}
};

std::ostream& operator<<(std::ostream& os, const Data& obj) {//Operator for std::cout>>
    os << "real: " << obj.real << ", image: " << obj.image;
    return os;
}

int main(){
Data A(2,1.5);
Data B(5,7.5);
//  A();
// Data()();
Data C{};
int x = A+12;
float y = B + 7.5f;
int z = A-12;
//  C = A + B;
// std::cout<<x<<std::endl;
// std::cout<<y<<std::endl;
// std::cout<<A<<std::endl;
std::cout<<z<<std::endl;

    return 0;
}