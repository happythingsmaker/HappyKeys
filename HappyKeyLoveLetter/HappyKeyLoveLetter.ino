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
