void one_color_all(int cred, int cgrn, int cblu) {
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
  safeDelay(thisdelay);
}

void new_rainbow_loop() {
  ihue -= 1;
  fill_rainbow( leds, LED_COUNT, ihue );
  LEDS.show();
  if (safeDelay(thisdelay)) return;
}

void rainbow_fade() {
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  if (safeDelay(thisdelay)) return;
}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for (uint16_t i = 0; i < LED_COUNT; i++) {
    setPixel(i, red, green, blue);
    FastLED.show();
    if (safeDelay(SpeedDelay)) return;
  }
}

void Ukraine() {
  for (uint16_t i = 0; i < LED_COUNT/2; i++) {
    setPixel(i, 0x00, 0x00, 0xff);
  }
  for (uint16_t i = LED_COUNT/2; i < LED_COUNT; i++) {
    setPixel(i, 0xff, 0xff, 0x00);
  }
  LEDS.show();
  LEDS.setBrightness(100);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(90);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(80);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(70);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(60);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(50);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(60);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(70);
  LEDS.show();
  delay(100);
  LEDS.setBrightness(80); 
  LEDS.show();
  delay(100);
  LEDS.setBrightness(90);  
  LEDS.show();
  delay(100);
  LEDS.setBrightness(100);
  LEDS.show();
  delay(100);
}

void ems_lightsSTROBE() { 
  int thishue = 0;
  int thathue = (thishue + 160) % 255;
  for (int x = 0 ; x < 5; x++ ) {
    for (int i = 0 ; i < TOP_INDEX; i++ ) {
      leds[i] = CHSV(thishue, thissat, 255);
    }
    LEDS.show(); if (safeDelay(thisdelay)) return;
    one_color_all(0, 0, 0);
    LEDS.show(); if (safeDelay(thisdelay)) return;
  }
  for (int x = 0 ; x < 5; x++ ) {
    for (int i = TOP_INDEX ; i < LED_COUNT; i++ ) {
      leds[i] = CHSV(thathue, thissat, 255);
    }
    LEDS.show(); if (safeDelay(thisdelay)) return;
    one_color_all(0, 0, 0);
    LEDS.show(); if (safeDelay(thisdelay)) return;
  }
}

void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {
  setAll(red, green, blue);

  int Pixel = random(LED_COUNT);
  setPixel(Pixel, 0xff, 0xff, 0xff);
  FastLED.show();
  if (safeDelay(SparkleDelay)) return;
  setPixel(Pixel, red, green, blue);
  FastLED.show();
  if (safeDelay(SpeedDelay)) return;
}

void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    FastLED.show();
    if (safeDelay(FlashDelay)) return;
    setAll(0, 0, 0);
    FastLED.show();
    if (safeDelay(FlashDelay)) return;
  }
}

boolean safeDelay(int delTime) {
  uint32_t thisTime = millis();
  while (millis() - thisTime <= delTime) {
    int tmp = ledMode;
    controlTick();
    if(ledMode != tmp)
      return true;
  }
  return false;
}
