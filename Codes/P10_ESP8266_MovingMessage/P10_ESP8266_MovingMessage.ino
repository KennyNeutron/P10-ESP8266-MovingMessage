#include <RoninDMD.h>  // Include lib & font

#include <fonts/Arial_Black_16.h>   //FONT1
#include <fonts/Arial14.h>          //FONT2
#include <fonts/DejaVuSans9.h>      //FONT3
#include <fonts/DejaVuSansBold9.h>  //FONT4
#include <fonts/Droid_Sans_12.h>    //FONT5
#include <fonts/Droid_Sans_16.h>    //FONT6
#include <fonts/Droid_Sans_24.h>    //FONT7
#include <fonts/SystemFont5x7.h>    //FONT8


#define FONT1 Arial_Black_16
#define FONT2 Arial14
#define FONT3 DejaVuSans9
#define FONT4 DejaVuSansBold9
#define FONT5 Droid_Sans_12
#define FONT6 Droid_Sans_16
#define FONT7 Droid_Sans_24
#define FONT8 SystemFont5x7


#define WIDTH 2  // Set width & height
#define HEIGHT 1


RoninDMD P10(WIDTH, HEIGHT);

String Message = "Hello World!";

char HEADER = 'A';
char FOOTER = 'B';

uint8_t getScrollSpeedTens;
uint8_t getScrollSpeedOnes;
uint8_t getScrollSpeed;
uint8_t getFONT;


void setup() {
  Serial.begin(9600);

  P10.begin();  // Begin the display & font
  P10.setFont(FONT1);

  P10.setBrightness(100);  // Set the brightness

  P10.drawText(0, 0, " :) ");  // P10.drawText(position x , position y, String type text);
}

void loop() {

  P10.loop();  // Run DMD loop

  get_SerialData();

  Scrolling_text(0, getScrollSpeed, Message);  // Call the function to write scrolling text on screen.
                                               // like -> Scrolling_text( position y , scroll speed, String type text);
                                               // or for not scroll -> P10.drawText(position x , position y, String type text);

}

void Scrolling_text(int text_height, int scroll_speed, String scroll_text) {
  static uint32_t pM;
  pM = millis();
  static uint32_t x = 0;
  scroll_text = scroll_text + " ";

  bool scrl_while = 1;
  int dsp_width = P10.width();
  int txt_width = P10.textWidth(scroll_text);

  while (scrl_while == 1) {

    P10.loop();
    delay(1);
    if (millis() - pM > scroll_speed) {
      switch (getFONT) {
        case 1:
          P10.setFont(FONT1);
          break;
        case 2:
          P10.setFont(FONT2);
          break;
        case 3:
          P10.setFont(FONT3);
          break;
        case 4:
          P10.setFont(FONT4);
          break;
        case 5:
          P10.setFont(FONT5);
          break;
        case 6:
          P10.setFont(FONT6);
          break;
        case 7:
          P10.setFont(FONT7);
          break;
        case 8:
          P10.setFont(FONT8);
          break;
      }
      P10.drawText(dsp_width - x, text_height, scroll_text);


      x++;
      if (x > txt_width + dsp_width) {

        x = 0;
        scrl_while = 0;
      }
      pM = millis();
    }
  }
}