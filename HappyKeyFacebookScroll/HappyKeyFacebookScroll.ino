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

