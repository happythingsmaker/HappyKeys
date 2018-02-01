#include <TrinketHidCombo.h>
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(0, LOW);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}

uint8_t delayMinValue = 30;
uint8_t delayMaxValue = 40;

void loop()
{

  if (digitalRead(2) == LOW) {
    TrinketHidCombo.mouseMove(0, 0, MOUSEBTN_LEFT_MASK); //press mouse left button
    TrinketHidCombo.mouseMove(0, 0, 0); //press mouse left button

    // for starcraft manufacturing
    TrinketHidCombo.print('1'); // call a factory (set as 5 ahead of time)
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.print('a'); // produce a tank
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, MOUSEBTN_LEFT_MASK); //press mouse left button
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, 0); //press mouse left button   // delay(random(50, 80));     // some random delay is needed between orders1a2a3a4a1a2a3a4a1a2a3a4a1a2a3a4a
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders


    TrinketHidCombo.print('2'); // call a factory (set as 5 ahead of time)
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.print('a'); // produce a tank
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, MOUSEBTN_LEFT_MASK); //press mouse left button
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, 0); //press mouse left button    //delay(random(50, 80));     // some random delay is needed between orders
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

    TrinketHidCombo.print('3'); // call a factory (set as 5 ahead of time)
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.print('a'); // produce a tank
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, MOUSEBTN_LEFT_MASK); //press mouse left button
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, 0); //press mouse left button    //delay(random(50, 80));     // some random delay is needed between orders
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders

    TrinketHidCombo.print('4'); // call a factory (set as 5 ahead of time)
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.print('a'); // produce a tank
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, MOUSEBTN_LEFT_MASK); //press mouse left button
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
    TrinketHidCombo.mouseMove(0, 0, 0); //press mouse left button  // delay(random(50, 80));     // some random delay is needed between orders
    delay(random(delayMinValue, delayMaxValue));     // some random delay is needed between orders
  } else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
}
