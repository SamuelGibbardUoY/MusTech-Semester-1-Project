/*Program to display simple messages and values on an LCD screen
Adapted from publically available GITHUB program for an arduino
01/11/23
Version 3
*/

/* Ensure RW LCD pin is connected to GND and connect a 10 K potentiometer with wiper connected to V0 and other ends to A and K LCD pins.
 Connect a 100 ohm resistor (ideally 500 Ohm) between A LCD pin and VDD.
 */

#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(D0, D1, D2, D3, D4, D5, TextLCD::LCD20x4); // Connect these nucleo pins to RS, E, D4, D5, D6 and D7 pins of the LCD
 
 

int main() 
{
    lcd.cls(); //clears the lcd screen
    lcd.locate(0,0); //sets the cursor to column 0 and row 1
    lcd.printf("Hello World!\n"); //displays the message Hello World on the LCD

    lcd.locate(0,1); //set cursor on row number 1 (bottom row)
    lcd.printf("The value is %d", 25); //displays an integer value
   
  
}