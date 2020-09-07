#include <Arduino.h>
#include <Wire.h>

#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_7C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>

#define SPI_MOSI 23
#define SPI_MISO -1
#define SPI_CLK 18

#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> display(GxEPD2_213_B72(ELINK_SS, ELINK_DC, ELINK_RESET, ELINK_BUSY));

const char HelloWorld[] = "Hello World!";

void printCentered(char *s) {
    display.setRotation(1);
    //display.setFont(&FreeMonoBold9pt7b);
    display.setFont(&FreeMonoBold18pt7b);
    display.setTextColor(GxEPD_BLACK);
    int16_t tbx, tby; uint16_t tbw, tbh;
    display.getTextBounds(s, 0, 0, &tbx, &tby, &tbw, &tbh);

    // center bounding box by transposition of origin:
    uint16_t x = ((display.width() - tbw) / 2) - tbx;
    uint16_t y = ((display.height() - tbh) / 2) - tby;
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(x, y);
        display.print(s);
    } while (display.nextPage());
}

void setup() {
    Serial.begin(115200);
    Serial.println();
    Serial.println("setup");
    delay(100);
    display.init(115200);
    
}

void loop() {
    char buf[16];
    ltoa(micros(), buf, 10);
    
    printCentered(buf);
    delay(60000);
}
