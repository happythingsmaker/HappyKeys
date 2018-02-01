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

      // for starcraft cheat key
      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("show me the money"); // "cheat key + enter"
      
      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("operation cwal"); // "cheat key + enter"

      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("black sheep wall"); // "cheat key + enter"
      
      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("power overwhelming"); // "cheat key + enter"
      
      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("the gathering"); // "cheat key + enter"
      
      TrinketHidCombo.println(); // enter
      TrinketHidCombo.println("food for thought"); // "cheat key + enter"

  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
}
