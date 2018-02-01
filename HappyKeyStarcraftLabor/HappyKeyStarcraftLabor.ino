// notice!! command center, Nexus or Hachery must set as 0 key

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

    TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_9); // save current state on 9
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders
    TrinketHidCombo.pressKey(0, 0);                      // release key
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders

    TrinketHidCombo.print("0");                       // call 0 (command center)
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders
    TrinketHidCombo.print("s");                      // drone, scv or prove
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders
    TrinketHidCombo.print("d");                      // drone, scv or prove
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders
    TrinketHidCombo.print("p");                      // drone, scv or prove
    delay(random(delayMinValue, delayMaxValue));       // some random delay is needed between orders

    TrinketHidCombo.print("9");                       // call 9 (previous saved step)
    

  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
}
