#include<iostream>
using namespace std;

class Complex{
        
        private :
                    float real_part;
                    float imaginary_part;
       public :
                   Complex(){
                           real_part = 0.0;
                           imaginary_part = 0.0;
                       }
                       
                  Complex(float real_part, float imaginary_part ){
                      
                         this -> real_part = real_part;
                         this -> imaginary_part = imaginary_part;
                  }                      
                     
    };
    
int main(){
         Complex  x = Complex(2,3);
         Complex  y = Complex(4,5);
    
    return 0;
    }