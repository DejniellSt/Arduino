/* This file contains sample code for an LCD display. 
 * The following buttons have been implemented for the movement: left, right, up, down, LCD reset and device operation time. 
 * Additionally, it includes a screen blanking function and a change of contrast.
*/
// LiquidCrystal - lcd library
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;
  
  return btnNONE;  // when all others fail, return this...
}

void setup()
{
  lcd.begin(16, 2);             
  lcd.setCursor(0,0);           
  lcd.print("Push the buttons");
  }

double value_V;

void loop()
{
   /* swich on/off display
     lcd.noDisplay();
     delay(500);
     lcd.display();
     delay(500);
    */ 

    // bit shift
    /*   for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      // scroll one position left:
        lcd.scrollDisplayLeft();
      // wait a bit:
        delay(300);
      }
  
      // scroll 29 positions (string length + display length) to the right
      // to move it offscreen right:
        for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      // scroll one position right:
         lcd.scrollDisplayRight();
      // wait a bit:
         delay(300);
      }
      // scroll 16 positions (display length + string length) to the left
      // to move it back to center:
      /*for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(300);
      }*/

    // delay at the end of the full loop:
    // delay(1000);
  
 lcd.setCursor(5,1);            // move cursor to second line "1" and 9 spaces over
 value_V = analogRead(A0)*5.0/1024.0;
 lcd.print(String("V:")+value_V+String(" ")+String("T:")+millis()/1000); // display current voltage and seconds elapsed since power-up

 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd_key = read_LCD_buttons();  // read the buttons

 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.print("RIGHT ");
     for (int positionCounter = 0; positionCounter < 29; positionCounter++) 
     {
      // scroll one position right:
      lcd.scrollDisplayRight();
      // wait a bit:
      delay(300);
      break;
     }
     break;
     }
   case btnLEFT:
     {
     lcd.print("LEFT   ");
     for (int positionCounter = 0; positionCounter < 13; positionCounter++)
     {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(300);
        break;
     }
      break;
     }
   case btnUP:
     {
     lcd.print("UP    ");
     break;
     }
   case btnDOWN:
     {
     lcd.print("DOWN  ");
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     break;
     }
     case btnNONE:
     {
     lcd.print("NONE");
     break;
     }
 }

}
