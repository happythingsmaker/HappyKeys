#include <TrinketHidCombo.h>
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(0, LOW);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}
const int delayTime = 10;

void loop()
{
  if (digitalRead(2) == LOW) {

    // MUTE
    TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE);

    // EXIT APPLICATION(Alt + F4)
    TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_ALT, KEYCODE_F4);
    TrinketHidCombo.pressKey(0, 0); // releasing keyboard

    // EXIT APPLICATION(Alt + F4) : for some environment
    TrinketHidCombo.pressKey(KEYCODE_LEFT_ALT, KEYCODE_F4);
    TrinketHidCombo.pressKey(0, 0); // releasing keyboard

    for (int i = 0; i < 51 ; i++) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    }

  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
}
