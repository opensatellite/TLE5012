#pragma once

#include <stdint.h>

class J1850CRC8 {
  private:
    static const uint8_t table[];
      
  public:
    static uint8_t calc(const uint8_t *buf, int len);
};

class TLE5012 {
  private:
    int csq_pin;
    int data_pin;
    int sck_pin;
    unsigned char ssc_delay;
    
  protected:
    //direct register access
    void select();
    void deselect();
    uint16_t read();
    void write(uint16_t x);

  public:
    TLE5012(int _csq, int _data, int _sck, unsigned char _ssc_delay = 0);

    static const uint16_t invalidAngle; //=0xffff
    uint16_t readAngle(); //0~32767 -> good, 0xffff -> invalid

    void begin();
    void end();
};
