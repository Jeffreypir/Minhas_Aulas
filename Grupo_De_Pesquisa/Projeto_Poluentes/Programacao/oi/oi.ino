#include <Arduino.h>
#include <SerialJeff.h>
#define LED 13
#define TIME 1000 

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    // Codigo aqui
    digitalWrite(LED, HIGH);
    delay(TIME);
    digitalWrite(LED, LOW);
    delay(TIME);
}
