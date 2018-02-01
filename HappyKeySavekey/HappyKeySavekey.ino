#include <TrinketHidCombo.h>
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(0, LOW);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}

const unsigned char delayMinValue = 30;
const unsigned char delayMaxValue = 40;

void loop()
{

  if (digitalRead(2) == LOW) {
    TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_S); // save current state on 9
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders
    TrinketHidCombo.pressKey(0, 0);                      // release key

  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }

}
