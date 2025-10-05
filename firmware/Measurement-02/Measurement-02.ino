/*  FH Aachen
    Interdisciplinary Project: MusiUeNet
    (Automatic Audio Measurement System)

    Measuring PCB (and associated software) by Nils Angelmann - 2022/2025
*/



//////////////////////////
/////// HARDWARE /////////
//////////////////////////

// Imports for Display
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

// Display pins
#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);  // Create Display Object named tft

// Colors fpr Display
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

// Pins
#define LEFT 7   // button left
#define ESC 6    // button escape
#define ENTER 5  // button enter
#define RIGHT 4  // button right

#define BURST 3   // Burst Output (PWM)
#define DETECT 2  // Detect Input
#define RELAY 0   // Relay Output
#define LED 1     // LED (Check)
#define DC A0     // DC Voltage -> ADC (Analog input)

// Constants
#define holdoff 0    // hold off between detected errors in ms -> max. 15 ms
#define debounce 15  // bounce time of switches in ms



//////////////////////////
/////// Variables ////////
//////////////////////////

#define OFFSET 4  // OFFSET for latency measurement (latency of the Arduino) between 3 and 4 ms
byte mode = 0;    // 0=menu, 1=detect, 2=burst
volatile unsigned int count = 0;
unsigned int prev_count = 1;
unsigned long duration = 0;
int baseline = 0;
int latency[10];
int avgLatency = 0;



void setup() {
  startup();
}



void loop() {

  if (mode == 0) {  // menu
    menuF();
  }

  else if (mode == 1) {  // detect
    detectF();
  }

  else if (mode == 2) {  // burst
    burstF();
  }
}
