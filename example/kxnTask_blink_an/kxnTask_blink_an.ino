#include "kxnTask_anled.h"
#include "kxnTask_anled.h"


kxnTask_anled anled13;
kxnTask_anled anled10;
kxnTask_anled anled11;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  anled13.setup(13, 500, 500);
  anled10.setup(10, 1000, 1000);
  anled11.setup(11, 2000, 2000);
}

// the loop function runs over and over again forever
void loop() {
  // anled13.loop();
  kxnTaskManager.run(millis());
  // digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  // delay(1000);                      // wait for a second
  // digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  // delay(1000);                      // wait for a second
}
