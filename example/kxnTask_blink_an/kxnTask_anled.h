#ifndef kxnTask_anled_H__
#define kxnTask_anled_H__

#include <kxnTask.h>
#include "debug.h"



CREATE_TASK(kxnTask_anled)

DEFINE_TASK_STATE(kxnTask_anled){
    kxnTask_anled_ON,
    kxnTask_anled_OFF,
};
uint8_t pin;
unsigned long timeOn;
unsigned long timeOff;

void setup(uint8_t pin_, unsigned long timeOn_, unsigned long timeOff_){
    pin = pin_;
    timeOn = timeOn_;
    timeOff = timeOff_;
    pinMode(pin, OUTPUT);
    setup();
}

void setup() {
  kxnTaskManager.add(this);
  // initialize digital pin LED_BUILTIN as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
  setState(kxnTask_anled_ON);
  AN_DBG_LN(F("kxnTask_anled setup"));
}

void loop() {
    // AN_DBG_LN(F("kxnTask_anled loop"));
    switch(getState()){
        case kxnTask_anled_ON:
            AN_DBG_LN(F("kxnTask_anled_ON"));
            digitalWrite(pin, HIGH);  // turn the LED on (HIGH is the voltage level)
            kDelay(timeOn);                      // wait for a second
            setState(kxnTask_anled_OFF);
            break;
        case kxnTask_anled_OFF:
            AN_DBG_LN(F("kxnTask_anled_OFF"));
            digitalWrite(pin, LOW);   // turn the LED off by making the voltage LOW
            kDelay(timeOff);                      // wait for a second
            setState(kxnTask_anled_ON);
            break;
        default:
            break;
    }
}

END
#endif