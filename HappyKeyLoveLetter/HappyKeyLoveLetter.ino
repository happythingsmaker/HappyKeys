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
  pinMode(2, INPUT_PULLUP);
  digitalWrite(0, LOW);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}
const int delayTime = 10;
bool prevState = HIGH;
int clickCount = 0;

void loop()
{
  if (digitalRead(2) == LOW) {

    if (prevState == HIGH) {

      printLetter(clickCount++);
      if (clickCount > 9) {
        clickCount = 0;
      }

    }
    prevState = LOW;
  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
    prevState = HIGH;
  }
}

void printLetter(int lineNumber) {
  switch (lineNumber) {
    case 0:
      TrinketHidCombo.println("Hello, it's me");
      break;
    case 1:
      TrinketHidCombo.println("I was wondering if after all these years you'd like to meet");
      break;
    case 2:
      TrinketHidCombo.println("To go over everything");
      break;
    case 3:
      TrinketHidCombo.println("They say that time's supposed to heal ya");
      break;
    case 4:
      TrinketHidCombo.println("But I ain't done much healing");
      break;
    case 5:
      TrinketHidCombo.println("Hello, can you hear me");
      break;
    case 6:
      TrinketHidCombo.println("I'm in California dreaming about who we used to be");
      break;
    case 7:
      TrinketHidCombo.println("When we were younger and free");
      break;
    case 8:
      TrinketHidCombo.println("I've forgotten how it felt before the world fell at our feet");
      break;
    case 9:
      TrinketHidCombo.println("http://HappyThingsMaker.com");
      break;

  }

}
