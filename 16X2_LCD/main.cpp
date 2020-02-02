#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(PC_11,PC_12,PD_4,PD_5,PD_6,PD_7);

DigitalIn button1(PE_3,PullUp);
DigitalIn button0(PE_4,PullUp);

enum State{
    FIRST,
    SECOND,
    THIRD
};

int main(){

    char first_item[] = "1. Mango";
    char second_item[] = "2. Orange";
    char third_item[] = "3. Banana";
    char fourth_item[] = "4. Apple";


   int button_press = 1;
   State menu_state = FIRST;

    while(1){

        lcd.cls();

        if(!button1){
            button_press ++;
            wait(0.1);
        }
        if(!button0){
            button_press--;
            wait(0.1);
        }

        if(button_press > 3){
            button_press = 3;
        }
        if(button_press < 0){
            button_press = 0;
        }

        if(button_press == 1){
            menu_state = FIRST;
        }
        if (button_press == 2){
           menu_state = SECOND;
        }
        if(button_press == 3){
            menu_state = THIRD;
        }

        if(menu_state == FIRST){
            lcd.locate(0,0);
            lcd.printf(first_item);
            lcd.locate(0,1);
            lcd.printf(second_item);
        }
        
        if(menu_state == SECOND){
            lcd.locate(0,0);
            lcd.printf(second_item);
            lcd.locate(0,1);
            lcd.printf(third_item);
        }
        
        if(menu_state == THIRD){
            lcd.locate(0,0);
            lcd.printf(third_item);
            lcd.locate(0,1);
            lcd.printf(fourth_item);
        }

        wait(0.1);
        }
    
    }