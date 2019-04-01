#ifndef _RS485MASTER_H_
#define _RS485MASTER_H_
#include "mbed.h"
#include "AsyncSerial.hpp"
//#include<deque>
#include<queue>

class RS485Master
{ 
    public:
        RS485Master(PinName Tx,PinName Rx,PinName enablePin,int baudrate);
        void changeBaud(int baudrate);
        void write(uint8_t *buff,int length);
        bool read(uint8_t* buff,int length);
        bool readable();
        void setTimeout(int byteRcvTime_us,int noComTime_us);
        
    private:
        void disableTransmit(int event);
        void readAndSetQueue();
        Timer _timer;
        AsyncSerial _serial;
        DigitalOut _enablePin;
        int _byteRcvTime_us,_noComTime_us;
};
#endif