#ifndef _AMT21_HPP_
#define _AMT21_HPP_

#include "mbed.h"
#include "RS485Master.hpp"

class AMT21
{
    public:
        AMT21(PinName Tx,PinName Rx,PinName enable);
        int readAngleRaw();
        int readAngleRaw(int &errorCode);
        void setZeroPosition();
        
    private:
        bool checkBits(uint8_t *data);
        bool getBit(uint8_t byte,int index);
        RS485Master _rs485;
        
};
#endif
