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
     
      // for starcraft manufacturing
      TrinketHidCombo.print('5'); // call a factory (set as 5 ahead of time)
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
      TrinketHidCombo.print('t'); // produce a tank
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

      TrinketHidCombo.print('6'); // call a factory (set as 5 ahead of time)
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
      TrinketHidCombo.print('t'); // produce a tank
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

      TrinketHidCombo.print('7'); // call a factory (set as 5 ahead of time)
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
      TrinketHidCombo.print('t'); // produce a tank
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

      TrinketHidCombo.print('8'); // call a factory (set as 5 ahead of time)
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
      TrinketHidCombo.print('t'); // produce a tank
      delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
}
