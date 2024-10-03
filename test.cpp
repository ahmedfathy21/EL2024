#include <cstddef>
#include <iostream>

class test;
class Data {
private:
 
  
  int y = 20;
  int *ptr = NULL;
friend class test;
friend void fun();
public:
 static int z;//initilized out of the line
int x = 10;
   Data(int x):x((x)){}

   Data(){std::cout<<"Default Constructor"<<std::endl;}    
    
    int getter();
    int getter()const;
};
int Data:: getter(){
   x = 20;
  return x;}
int Data::getter()const{
  return y;
  }   


void fun(){
  Data h;
   std::cout<<h.x<<"  "<<h.y<<std::endl;
}
Data l;

int main() {
fun();
l.z = 20;


  return 0;
} 