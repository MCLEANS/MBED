#include "mbed.h"
 

 
DigitalOut led(PA_6);
DigitalIn button(PE_4);

int main() {
  
    
    while(1) {

        if(!button){
             led = 1;
            wait(1);
            led = 0;
            wait (1);
        }
       
       else{
           led = 0;
       }
    }
}
