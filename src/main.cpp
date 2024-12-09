#include "Barriere.h"
#include "Vehicule.h"
#include "Parking.h"
#include <Arduino.h>

Parking::Vehicule vehicule;
Parking::Barriere barriere;
unsigned long lastActionTime = 0;
const unsigned long delayTime = 2000;
bool barrierOpen = false;

void setup() {
    pinMode(VEHICLE_IR, INPUT);
    pinMode(BUTTON, INPUT);
    pinMode(LED_Green, OUTPUT);
    pinMode(LED_Orange, OUTPUT);
    pinMode(LED_Red, OUTPUT);
}

void loop() {
    if (vehicule.detecterVehicule() && !barrierOpen) {
        barriere.open();
        lastActionTime = millis();
        barrierOpen = true;
    }

    if (barrierOpen && (millis() - lastActionTime >= delayTime)) {
        if (vehicule.detecterVehiculeApresBarriere()) {
            barriere.close();
            barrierOpen = false;
        }
    }
}
