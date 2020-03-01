#include <SPI.h>
#include <Wire.h>
#include "sh1106.h"


#define VCCSTATE SH1106_SWITCHCAPVCC
#define WIDTH     128
#define HEIGHT     64
#define NUM_PAGE    8  /* number of pages */

#define OLED_RST    9 
#define OLED_DC     8
#define OLED_CS    10
#define SPI_MOSI   11    /* connect to the DIN pin of OLED */
#define SPI_SCK    13     /* connect to the CLK pin of OLED */

uint8_t oled_buf[WIDTH * HEIGHT / 8];
void setup() {
  Serial.begin(9600);
  Serial.print("OLED Example\n");

  /* display an image of bitmap matrix */
  SH1106_begin();
  SH1106_clear(oled_buf);
//  Place for loading screen
//  SH1106_bitmap(0, 0, Waveshare12864, 128, 64, oled_buf);
//  SH1106_display(oled_buf);
//  delay(2000);
//  SH1106_clear(oled_buf);

  /* display images of bitmap matrix */
//  SH1106_bitmap(0, 2, Signal816, 16, 8, oled_buf); 
//  SH1106_bitmap(24, 2,Bluetooth88, 8, 8, oled_buf); 
//  SH1106_bitmap(40, 2, Msg816, 16, 8, oled_buf); 
//  SH1106_bitmap(64, 2, GPRS88, 8, 8, oled_buf); 
//  SH1106_bitmap(90, 2, Alarm88, 8, 8, oled_buf); 
//  SH1106_bitmap(112, 2, Bat816, 16, 8, oled_buf); 
//
//  SH1106_string(0, 0, "Tmp[C]", 12, 1, oled_buf); 
//  SH1106_string(46, 0, "P[hPa]", 12, 1, oled_buf); 
//  SH1106_string(90, 0, "Hum[%]", 12, 1, oled_buf);
//
//  SH1106_char(40, 16, '|',12,1, oled_buf);
//  SH1106_char(80, 16, '|',12,1, oled_buf);
//  SH1106_char(40, 32, '|',12,1, oled_buf);
//  SH1106_char(80, 32, '|',12,1, oled_buf);
//  SH1106_char(40, 48, '|',12,1, oled_buf);
//  SH1106_char(80, 48, '|',12,1, oled_buf);

//  SH1106_char1616(48, 0, '1', oled_buf);
//  SH1106_char1616(64, 0, '2', oled_buf);
//  SH1106_char1616(80, 0, ':', oled_buf);
//  SH1106_char1616(96, 0, '3', oled_buf);
//  SH1106_char1616(112, 0, '4', oled_buf);
//  SH1106_char1616(80, 16, ':', oled_buf);
//  SH1106_char1616(96, 0, '5', oled_buf);
//  SH1106_char1616(112, 0, '6', oled_buf);
//
//  SH1106_display(oled_buf); 
}

void loop() {

  SH1106_clear(oled_buf);
// Head
  SH1106_string(0, 0, "Temp", 12, 1, oled_buf); 
  SH1106_string(46, 0, "P[hPa]", 12, 1, oled_buf); 
  SH1106_string(90, 0, "Hum[%]", 12, 1, oled_buf);

// Dashes
  SH1106_char(40, 16, '|',12,1, oled_buf);
  SH1106_char(80, 16, '|',12,1, oled_buf);
  SH1106_char(40, 32, '|',12,1, oled_buf);
  SH1106_char(80, 32, '|',12,1, oled_buf);
  SH1106_char(40, 48, '|',12,1, oled_buf);
  SH1106_char(80, 48, '|',12,1, oled_buf);

// Values  
  char temperature[5] ;
  dtostrf(34.9,4,1,temperature);
  
  char pressure[5];
  dtostrf(34.9,4,1,temperature);
  SH1106_string(0, 16, temperature, 16, 1, oled_buf); 
  SH1106_string(8, 32, "C*", 16, 1, oled_buf); 
  SH1106_string(46, 32, pressure, 12, 1, oled_buf); 
  SH1106_string(8, 32, "C*", 16, 1, oled_buf); 
  
  SH1106_display(oled_buf); 
  delay(1000);
  


}
