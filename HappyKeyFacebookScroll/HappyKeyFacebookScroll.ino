/*
  ------------------------------------ Parts ---------------------------------

  Cherry Key Switch  http://amzn.to/2BEygaX
  Attiny85  http://amzn.to/2FvhOw6
  Keycap  http://amzn.to/2DO1ydg
  Micro USB cable http://amzn.to/2Enrycm
  Blu-Tack Reusable Adhesive  http://amzn.to/2DQgOlT
  Finished Product(soon)  https://www.etsy.com/people/xhjkunl8?ref=hdr_user_menu
  Material Kit(soon)  https://www.etsy.com/people/xhjkunl8?ref=hdr_user_menu

  ------------------------------------ Tools ---------------------------------

  Filament for 3d print (PLA 1.75mm) http://amzn.to/2DhxPpo
  Hot melt glue gun   http://amzn.to/2CMf8cE
  3D printer (P802MA) http://amzn.to/2CWuVZE
  Soldering Iron Kit  http://amzn.to/2Gv8UA3

  ------------------------------------ Instruction --------------------------


  Source Code https://github.com/happythingsmaker/HappyKeys
  3D model file (for 3d printer) https://www.thingiverse.com/thing:2777861
  Youtube https://youtu.be/Y8Oh4aj96gU
  Manual https://github.com/happythingsmaker/HappyKeys/blob/master/README.md
  Schematic https://github.com/happythingsmaker/HappyKeys

  ------------------------------------ Follow Me ---------------------------------

  Instagram:     https://www.instagram.com/happythingsmaker/
  Facebook:      https://www.facebook.com/happyThingsMaker/
  Blog : http://happyThingsMaker.com
*/

#include <TrinketHidCombo.h>
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(0, LOW);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}
const int delayTime = 10;
bool prevState = HIGH;
bool autoScroll = false;
unsigned long lastScrollTime = 0;


void loop()
{
  if (digitalRead(2) == LOW) {
    if (prevState == HIGH) {
      if (autoScroll) {
        autoScroll = false;
      } else {
        autoScroll = true;
        lastScrollTime = 0;
      }
    }
    prevState = LOW;
  } else {
    prevState = HIGH;

  }

  if (autoScroll) {
    if (millis() - lastScrollTime > 1000) {
      TrinketHidCombo.pressKey(0, KEYCODE_PAGE_DOWN);
      TrinketHidCombo.pressKey(0, 0);
      lastScrollTime = millis();
    }
  } else {
    TrinketHidCombo.poll();
  }
  digitalWrite(1, autoScroll);

  delay(50);
}

