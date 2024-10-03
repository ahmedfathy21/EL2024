#include<iostream>
#include <string>
#include <bits/stdc++.h>
class Data{
public:
std::string str;
int courser; 

Data& operator+=(const std::string message){
    this->str += message;
    return  *this;
}
bool operator >(const Data &data1){
    return this->str > data1.str;
}
void operator++(){ this->courser++;}// pre increment


int operator++(int ){ // Post increment
    int temp = this->courser;
     this->courser++;
     return temp;
    
    ;}

};



std::string operator+(const Data &data, const std::string &message){
return data.str + message;

}
std::string operator-(const Data &data, const std::string &message){
return data.str + message;

}


int main(){
Data data{"Hello Ahmed \n"};
Data data1{"Hello"};

std::string  message = "Welcome Egypt";
data += message;
// data.display();
std::string result = data + message; // Operator>> (data + message)
std::string result1 = data - message; // Operator>> (data + message)

std::cout<<result<<std::endl;
std::cout<<result1<<std::endl;
if(data > data1){
        std::cout<<" data1 is less than data "<<std::endl;

}
else {
        std::cout<<" data1 is bigger than data "<<std::endl;
}
++data;
std::cout<<data.courser<<std::endl;

int y =data++;
std::cout<<y<<std::endl;
    return  0;
}