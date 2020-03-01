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

#define DHT22PIN 4    //przypisanie pinu 2 Arduino jako odczyt z sensora
DFRobot_BMP388_I2C bmp388;

uint8_t oled_buf[WIDTH * HEIGHT / 8];

void setup() {

    Serial.begin(9600);                    //inicjalizacja monitora szeregowego

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
    int chk = DHT22.read(
            DHT22PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym

//    TODO powiadomienie o stanie sesora
    Serial.print("Stan sensora: ");
    switch (chk) {
        case DHTLIB_OK:
            Serial.print("OK\t");
            break;
        case DHTLIB_ERROR_CHECKSUM:
            Serial.println("Błąd sumy kontrolnej");
            break;
        case DHTLIB_ERROR_TIMEOUT:
            Serial.println("Koniec czasu oczekiwania - brak odpowiedzi");
            break;
        default:
            Serial.println("Nieznany błąd");
            break;
    }

//    Serial.print("\n");
//    Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
//    Serial.print((float)DHT22.humidity, 2);
    //   Serial.print("\t\t");
//    Serial.print("\n");
//    Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
//    Serial.println((float)DHT22.temperature, 2);





    float temperature_f = DHT22.temperature;
    char temperature[5];
    dtostrf(temperature_f, 4, 1, temperature);


    float pressure_f = bmp388.readPressure() / 100;
    char pressure[7];
    dtostrf(pressure_f, 6, 2, pressure);

    float humidity_f = DHT22.humidity;
    char humidity[4];
    dtostrf(humidity_f, 3, 1, humidity);

//    int seconds = Wire.read(); // get seconds
//    int minutes = Wire.read(); // get minutes
//    int hours = Wire.read();   // get hours

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


    delay(10000);                                  //opóźnienie między kolejnymi odczytami - 10 s
}
