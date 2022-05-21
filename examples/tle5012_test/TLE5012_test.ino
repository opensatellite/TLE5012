#include <TLE5012.h>

unsigned char ssc_delay = 0; // SSC clock frequency adjust, 0 = fastest, 255 = slowest
TLE5012 enc(D8, D9, D10, ssc_delay);

void setup() {
    Serial.begin(115200);
    enc.begin();
}

void loop() {
    unsigned int angle = enc.readAngle();       //took 1ms on ATmega328P
    Serial.print("Angle: ");
    if(angle == enc::invalidAngle) {
        Serial.println("invalid");
    } else {
        Serial.println(x);
    }
}
