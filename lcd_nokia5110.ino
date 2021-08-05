#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

//Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, D/C, CS, RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
display.begin();                          //uruchom ekran
display.setContrast(40);                  //ustaw kontrast
display.clearDisplay();                   //wyczyść bufor ekranu
}

void loop() {
  display.setTextSize(1);                   //ustaw rozmiar czcionki na 1
  display.setTextColor(BLACK);              //ustaw kolor tekstu na czarny
  display.setCursor(3,5);                   //ustaw kursor w pozycji 3 kolumna 5 wiersz
  display.print("Test);
  display.drawLine(3, 13, 81, 13, BLACK);  //draws a line from (x1,x2) to (y1,y2)

  display.setTextColor(WHITE, BLACK);        // 'inverted' text
  display.setCursor(0,17);                   //ustaw kursor w pozycji 1 kolumna 12 wiersz
  display.print("LCD Nokia5110");

  display.setTextColor(BLACK);   
  display.setCursor(3,30);
  display.setTextSize(2);
  display.print("TEST");

  display.drawRect(1, 28, 50, 18, BLACK);  //draws a rectangle from (x1,y1) to (x2,y2)

  display.drawTriangle(61, 28, 78, 37, 61, 45, BLACK);
  display.drawLine(53, 28, 53, 45, BLACK);
  display.drawLine(55, 28, 55, 45, BLACK); 
  display.drawLine(57, 28, 57, 45, BLACK);
  display.drawLine(59, 28, 59, 45, BLACK);
  display.display();
}
