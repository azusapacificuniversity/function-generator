#include <M5StickCPlus.h>
#include <WiFi.h>
//Variable to rotate through different waves
int currWaveKind = 0;
//Wipe the LCD and print the header, as well as the graph lines
void wipeLCDText() {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(52, 5);
    M5.Lcd.setTextSize(1);
    M5.Lcd.println("APU Function Generator");
    M5.Lcd.setTextSize(2);
    M5.Lcd.drawFastVLine((M5.Lcd.width() / 2) - 1, 30, 150, WHITE);
    M5.Lcd.drawFastHLine(0, (M5.Lcd.height() / 2) + 12, M5.Lcd.width(), WHITE);
}
//TODO - draw the sine wave
void sineWave() {
    wipeLCDText();
    M5.Lcd.setTextColor(RED);
    M5.Lcd.println("Sine Wave");
}
//Draws a square wave
void squareWave() {
    wipeLCDText();
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.println("Square Wave");
    M5.Lcd.drawLine(0, 110, 45, 110, GREEN);
    M5.Lcd.drawLine(45, 110, 45, 50, GREEN);
    M5.Lcd.drawLine(45, 50, 95, 50, GREEN);
    M5.Lcd.drawLine(95, 50, 95, 110, GREEN);
    M5.Lcd.drawLine(95, 110, 145, 110, GREEN);
    M5.Lcd.drawLine(145, 110, 145, 50, GREEN);
    M5.Lcd.drawLine(145, 50, 195, 50, GREEN);
    M5.Lcd.drawLine(195, 50, 195, 110, GREEN);
    M5.Lcd.drawLine(195, 110, 245, 110, GREEN);
}
//Draws a sawtooth wave
void sawtoothWave() {
    wipeLCDText();
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.println("Sawtooth Wave");
    M5.Lcd.drawLine(0, 110, 45, 50, BLUE);
    M5.Lcd.drawLine(45, 50, 90, 110, BLUE);
    M5.Lcd.drawLine(90, 110, 135, 50, BLUE);
    M5.Lcd.drawLine(135, 50, 180, 110, BLUE);
    M5.Lcd.drawLine(180, 110, 225, 50, BLUE);
    M5.Lcd.drawLine(225, 50, 270, 110, BLUE);
}

void setup() {
    //Allegedly decreasing clock to 80 Mhz increases battery by 20%
    setCpuFrequencyMhz(80);
    // Turn off Wifi and Bluetooth at the hardware level to save battery
    WiFiClass::mode(WIFI_OFF);
    btStop();
    //Init M5Stick
    M5.begin();
    M5.Lcd.setRotation(3);
    //Prepare screen for drawing
    sineWave();
}

void loop() {
    M5.update();
    //Rotate through the waves if the a button is pressed
    if (M5.BtnA.isPressed() || M5.BtnB.isPressed()){
        ++currWaveKind;
        switch (currWaveKind % 3) {
            case 0:
                sineWave();
                break;
            case 1:
                squareWave();
                break;
            case 2:
                sawtoothWave();
                break;
            default:
                break;
        }
        delay(375);
    }
    delay(100);
}