#include "dht.h"
#include "DFRobot_BMP388.h"
#include "DFRobot_BMP388_I2C.h"
#include "Wire.h"
#include "SPI.h"
#include "math.h"
#include "bmp3_defs.h"
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

dht DHT22;
#define DHT22PIN 4    //set 4 as receive from sensor

DFRobot_BMP388_I2C bmp388;

//screen
uint8_t oled_buf[WIDTH * HEIGHT / 8];


void setup() {

    Serial.begin(9600);  //init serial monitor

//BMP
    bmp388.set_iic_addr(BMP3_I2C_ADDR_SEC);
    /* Initialize bmp388*/
    while (bmp388.begin()) {
        Serial.println("Initialize error!");
        delay(1000);
    }

    SH1106_begin();
    Serial.println("collecting data - started");

}

void loop() {

    DHT22.read(DHT22PIN);         //read data
    float temperature_f = DHT22.temperature;
    char temperature[5];
    dtostrf(temperature_f, 4, 1, temperature);


    float pressure_f = bmp388.readPressure() / 100;
    char pressure[7];
    dtostrf(pressure_f, 6, 2, pressure);

    float humidity_f = DHT22.humidity;
    char humidity[4];
    dtostrf(humidity_f, 3, 1, humidity);

    SH1106_clear(oled_buf);
// Head 1st col
    SH1106_string(0, 16, "Temp:", 16, 1, oled_buf);
    SH1106_string(0, 32, "Pres:", 16, 1, oled_buf);
    SH1106_string(0, 48, "Hum:", 16, 1, oled_buf);


// Values
    SH1106_string(50, 16, temperature, 16, 1, oled_buf);
    SH1106_string(112, 16, "C", 16, 1, oled_buf);
    SH1106_string(106, 14, "o", 12, 1, oled_buf);

    SH1106_string(50, 32, pressure, 16, 1, oled_buf);
    SH1106_string(106, 34, "hPa", 12, 1, oled_buf);

    SH1106_string(50, 48, humidity, 16, 1, oled_buf);
    SH1106_string(106, 48, "%", 16, 1, oled_buf);

    SH1106_display(oled_buf);

    delay(10000);                                  //delay between data read - 10 s

}
