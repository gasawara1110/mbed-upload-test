/**
 * @file RS485Master.cpp
 * @brief RS485Master control class
 * @author K.Ogasawara
 * @date 2018/7/27
 */
#include "RS485Master.hpp"
#include "mbed.h"


/** constructor
* @param[in] Tx Name of serial tx pin
* @param[in] Rx Name of serial rx pin
* @param[in] enablePin Name of RS485 transmit enable pin
* @param[in] baudrate RS485Master baudrate
*/
RS485Master::RS485Master(PinName Tx,PinName Rx,PinName enablePin,int baudrate):_serial(Tx,Rx,baudrate),_enablePin(enablePin)
{
    _enablePin = 0;
    _byteRcvTime_us = (int)(1000000.0f*10.0f/(float)baudrate);    //time taken to receive 1 byte
    _noComTime_us = (int)((float)_byteRcvTime_us*1.5f);     //no communication time;
}

/** change baudrate 
* @param[in] baudrate baudrate of RS485MasterMasterMasterMaster
*/
void RS485Master::changeBaud(int baudrate)
{
    _serial.baud(baudrate);
}

/** transmit data  
* @param[in] *buff The buffer which include transmit data 
* @param[in] length data length
*/
void RS485Master::write(uint8_t *buff,int length)
{
    _enablePin = 1;
    //_callback.attach(this,&RS485Master::disableTransmit);   //テストで追加
    _serial.write(buff,length);
    _serial.wait();
    wait_us(_noComTime_us);
    _serial.abort_write();      //追加
    _enablePin = 0;    
}


/** deisable transmit(set enable pin low)
* @param[in] event Type or event(dont care)
*/
void RS485Master::disableTransmit(int event)
{
    _enablePin = 0;    
}

/** read received data
* @param[out] buffer to stroage received data
* @param[in] length buffer length
*/
bool RS485Master::read(uint8_t* buff,int length)
{
    //_enablePin = 0; //追加
    int limitTime = (_byteRcvTime_us*length+_noComTime_us)*3.0f;
    //int limitTime = (_byteRcvTime_us*length+_noComTime_us)*100.0f;
    int i=0;
    _timer.reset();
    _timer.start();
    
    while(_timer.read_us() < limitTime)
    {
        if(readable()==true)
        {
            buff[i] = _serial.getc();
            i++;
            if(i==length)
            {
                _timer.stop();
                //modbus rtu classでやるべき
                wait_us(_noComTime_us*2);
                return true;
            }
        }
    }
    _timer.stop();
    return false;
}

/** determine if there is data to read in received buffer
* @return true:data exist.false:no data
*/
bool RS485Master::readable()
{
    bool result = _serial.readable();
    return result;
}


