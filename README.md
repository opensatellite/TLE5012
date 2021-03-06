# TLE5012

Arduino library interfacing TLE5012B magnetic encoder over SSC.  
TLE5012B is an magnetic angle sensor (absolute encoder) manufacutured by Infineon technonlogies.  
This library has less than 200 lines of code. It uses GPIO pins to emulate SSC timing. Work with any arduino boards or variants.  

# Usage

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

# License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
