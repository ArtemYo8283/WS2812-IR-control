#include "FastLED.h"          // Library to work with WS2812
#include "IRLremote.h"        // Library to work with IR remote
#define LED_COUNT 86          // Led count (CHECK, IT CAN BE DIFFERENT IN YOU)
#define LED_DT 13             // Strip PIN (CHECK, IT CAN BE DIFFERENT IN YOU)
#define pinIR 2               // IR PIN (CHECK, IT CAN BE DIFFERENT IN YOU)
#define MOD_COUNT 15 // Count of animation (CHECK, IT CAN BE DIFFERENT IN YOU)

CHashIR IRLremote;

int ledMode = -1;             //Brightness of strip
bool OK = false;              //ON/OFF flag
int Brightness = 100;         //Brightness of strip

// Variables for effects
int BOTTOM_INDEX = 0;   
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];   

int thisdelay = 20;  
int thishue = 0;        
int thissat = 255;      

int idex = 0;
int ihue = 0;           

void setup()
{
  Serial.begin(9600);                                   // Initiates a serial connection 
  Serial.println(F("Startup"));
  LEDS.setBrightness(100);                              // Set start Brightness

  LEDS.addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT);   // Set LED-strip settings
  one_color_all(255, 0, 0);                             // Set Red color for start
  LEDS.show();                                          // Show

  if (!IRLremote.begin(pinIR)){                         // Set IR pin and check pin
      Serial.println(F("You did not choose a valid pin."));
    }
}

void loop() {
    controlTick();
    effectsTick();
}
