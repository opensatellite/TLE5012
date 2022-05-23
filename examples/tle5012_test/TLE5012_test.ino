#include <TLE5012.h>

unsigned char ssc_delay = 0; // SSC clock frequency adjust, 0 = fastest, 255 = slowest
TLE5012 enc(8, 9, 10, ssc_delay);

void setup() {
    Serial.begin(115200);
    enc.begin();
}

void loop() {
    unsigned int angle = enc.readAngle();
    Serial.print("Angle: ");
    if(angle == TLE5012::invalidAngle) {
        Serial.println("invalid");
    } else {
        Serial.println(angle);
    }
}
