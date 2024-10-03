#include <iostream>

class car { 
    public:
        //default constructor
    car(){
        std::cout<<"car constructor"<<std::endl;
    }
        //copy constructor
    car(const car &other){
        std::cout<<"car copy constructor"<<std::endl;
    }
        //move constructor
    car(car &&other){
        std::cout<<"car move constructor"<<std::endl;
    }
        //destructor
    ~car(){
        std::cout<<"car destructor"<<std::endl;
    }
};
class kai : public car{
    public:
        //default constructor
    kai(){
        std::cout<<"kai constructor"<<std::endl;
    }
        //copy constructor
    kai(const kai &other){
        std::cout<<"kai copy constructor"<<std::endl;
    }
        //move constructor
    kai(kai &&other){
        std::cout<<"kai move constructor"<<std::endl;
    }
        //destructor
    ~kai(){
        std::cout<<"kai destructor"<<std::endl;
    }
};
class kind : public kai{
    public:
        //default constructor
    kind(){
        std::cout<<"kind constructor"<<std::endl;
    }
        //copy constructor
    kind(const kind &other){
        std::cout<<"kind copy constructor"<<std::endl;
    }
        //move constructor
    kind(kind &&other){
        std::cout<<"kind move constructor"<<std::endl;
    }
        //destructor
    ~kind(){
        std::cout<<"kind destructor"<<std::endl;
    }
};


int main(){
    kind k;
    return 0;
}