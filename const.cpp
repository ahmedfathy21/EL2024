#include <iostream>

constexpr int fun(int x,int y){
   int q = 0;
// std::cin<<q<<std::endl;
        x= 1;
        for ( int i = 0; i < 5; i++)
        {
            x+=i;
        }
    return  x+y ;
}
int main(){
constexpr int z = fun(8, 10);
std::cout<<z;
return 0;
}