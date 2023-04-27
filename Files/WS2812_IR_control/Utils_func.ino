void controlTick() {
  if (IRLremote.available()) {
      
      auto data = IRLremote.read();
      if (data.command != 292984781) {
        Serial.println(data.command);
        thisdelay = 300;
        switch(data.command){
          case 1314628525: 
            Serial.println('1');
            ledMode = 1;
            thisdelay = 20;
          break;
          case 3843860141:
            Serial.println('2');
            ledMode = 2;
            thisdelay = 20;
          break;
          case 3792167341:
            Serial.println('3');
            ledMode = 3;
            thisdelay = 20;
          break;
          case 1366321325:
            Serial.println('4');
            ledMode = 4;
            thisdelay = 20;
          break;
          case 462609837:
            Serial.println('5');
            ledMode = 5;
            thisdelay = 20;
          break;
          case 2888455853:
            Serial.println('6');
            ledMode = 6;
            thisdelay = 30;
          break;
          case 1417983661:
            Serial.println('7');
            ledMode = 7;
            thisdelay = 300;
          break;
          case 3525530541:
            Serial.println('8');
            thisdelay = 40;
            ledMode = 8;
          break;
          case 3745467309:
            Serial.println('9');
            thisdelay = 50;
            ledMode = 9;
          break;
          case 4035585709:
            Serial.println('0');
            thisdelay = 300;
            if(Brightness > 80) {
                Brightness = 80;
              }
            ledMode = -1;
            LEDS.setBrightness(Brightness);
            one_color_all(255, 255, 255);
            LEDS.show();
          break;
          case 1759794861:
            Serial.println('*');
            thisdelay = 20;
          break;
          case 354211501:
            Serial.println('#');
            thisdelay = 20;
          break;
          case 4087278509:
            Serial.println("Up");
            if(Brightness + 10 > 100){
              Brightness = 100;
            }
            else {
              Brightness += 10;
            }
            LEDS.setBrightness(Brightness);
            LEDS.show();
            thisdelay = 20;
          break;
          case 3230267053:
            Serial.println("Down");
            if(Brightness - 10 < 0){
              Brightness = 0;
            }
            else {
              Brightness -= 10;
            }
            LEDS.setBrightness(Brightness);
            LEDS.show();
            thisdelay = 20;
          break;
          case 3797160109:
            Serial.println("Left");
            if(ledMode - 1 < 1){
              ledMode = MOD_COUNT;
            }
            else {
              ledMode -= 1;
            }
            thisdelay = 20;
          break;
          case 349066413:
            Serial.println("Right");
            if(ledMode + 1 > MOD_COUNT){
              ledMode = 1;
            }
            else {
              ledMode += 1;
            }
            thisdelay = 20;
          break;
          case 696022701:
            Serial.println("Ok");
            if( OK == false){
              OK = true;
              LEDS.setBrightness(0);
            }
            else {
              OK = false;
              LEDS.setBrightness(100);
            }
            LEDS.show(); 
            thisdelay = 20;
          break;
        }
      }
    }
}

void effectsTick() {
      switch (ledMode) {
      case 1: 
        one_color_all(255, 0, 0); 
        LEDS.show(); 
      break;  
      case 2: 
        one_color_all(0, 255, 0);
        LEDS.show(); 
      break;  
      case 3: 
        one_color_all(0, 0, 255);
        LEDS.show(); 
      break;
      case 4:
        rainbow_fade();
      break;
      case 5:
        new_rainbow_loop();
      break;
      case 6:
        SnowSparkle(0x10, 0x10, 0x10, thisdelay, random(100, 1000));
      break;
      case 7:
        Ukraine();
      break;  
      case 8:
        ems_lightsSTROBE();
      break;
      case 9:
        Strobe(0xff, 0xff, 0xff, 10, thisdelay, 1000); break;
      case 10:
        one_color_all(0, 255, 255);
        LEDS.show();
      break;  
      case 11:
        one_color_all(255, 0, 255);
        LEDS.show();
      break;  
      case 12:
        one_color_all(255, 255, 0);
        LEDS.show();
      break;  
      case 13:
        one_color_all(102, 0, 204);
        LEDS.show();
      break;  
      case 14:
        one_color_all(128, 255, 0);
        LEDS.show();
      break;  
      case 15:
        one_color_all(255, 128, 0);
        LEDS.show();
      break;  
    }
}
void setPixel(int Pixel, byte red, byte green, byte blue) {
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < LED_COUNT; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
