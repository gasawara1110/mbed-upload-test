#include "mbed.h"
#include "AMT21.hpp"

int main()
{
    AMT21 ABSEnc(D8,D2,D3);
    Serial pc(USBTX,USBRX,115200);
    int angle = 0;
    int errorCode = 0;
    
    ABSEnc.setZeroPosition();
    while(1)
    {
        angle = ABSEnc.readAngleRaw(errorCode);  
        pc.printf("ang:%d error:%d\r\n",angle,errorCode);
        wait(0.1);
    }
}
    