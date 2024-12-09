#include "Parking.h"
#include "Vehicule.h"
#include <Arduino.h>

namespace Parking {

    bool Vehicule::detecterVehicule() {
        if (digitalRead(VEHICLE_IR) == LOW) {
            digitalWrite(LED_Green, LOW);   
            digitalWrite(LED_Red, HIGH); 
            digitalWrite(LED_Orange, LOW); 
            return true;
        }
        else if(digitalRead(VEHICLE_IR) == HIGH){
            digitalWrite(LED_Green, LOW);   
            digitalWrite(LED_Orange, HIGH);    
            digitalWrite(LED_Green, LOW);    
            return false;
        }
        else if(digitalRead(BUTTON) == HIGH){
            digitalWrite(LED_Green, HIGH);   
            digitalWrite(LED_Orange, LOW);    
            digitalWrite(LED_Green, LOW);    
        }
    }
    bool Vehicule::detecterVehiculeApresBarriere() {
        if (digitalRead(VEHICLE_IR) == LOW) {
            return true;
        }
        return false;
    }

}
