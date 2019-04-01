/**
 * @file AMT21.cpp
 * @brief AMT21 absolute encoder reading class
 * @author K.Ogasawara
 * @date 2019/3/20
 */
 #include "mbed.h"
 #include "AMT21.hpp"
 #include "BitConverter.hpp"
 
 /* constructor
 *@param[in] Tx Serial Tx Pin
 *@param[in] Rx Serial Rx Pin
 *@param[in] enable Transmit enable pin
 */
 AMT21::AMT21(PinName Tx,PinName Rx,PinName enable):_rs485(Tx,Rx,enable,2000000)
{}

/* read raw angle value from abs encoder
* @return raw angle value (0~4095)
*/
int AMT21::readAngleRaw()
{
    uint8_t sendBuff[1];
    uint8_t receiveBuff[2];
    sendBuff[0] = 0x54;         //single turn position read command
    _rs485.write(sendBuff,1);
    _rs485.read(receiveBuff,2);
    receiveBuff[1] = receiveBuff[1] & 0b00111111;   //mask checkbits
    uint16_t temp = BitConverter::toUint16(receiveBuff,0) >> 2; //2bit right shift
    BitConverter::toArray(receiveBuff,temp,0);
    int angleRaw = (int)(BitConverter::toInt16(receiveBuff,0));    
    return angleRaw;
}
/* read raw angle value and error code from abs encoder
* @param[out] &errorCode 0:no error 1:no response 2:checksum error
* @return raw angle value (0~4095)
*/
int AMT21::readAngleRaw(int &errorCode)
{
    uint8_t sendBuff[1];
    uint8_t receiveBuff[2];
    sendBuff[0] = 0x54;         //single turn position read command
    _rs485.write(sendBuff,1);
    
    //check no response error
    if(_rs485.read(receiveBuff,2) == false)
    {
        errorCode = 1;          //no response error
        return 0;
    }
    
    //calcurate check sum
    if(checkBits(receiveBuff) == false)
    {
        errorCode = 2;          //cehcksum error
        return 0;
    }
         
    receiveBuff[1] = receiveBuff[1] & 0b00111111;   //mask checkbits
    uint16_t temp = BitConverter::toUint16(receiveBuff,0) >> 2; //2bit right shift
    BitConverter::toArray(receiveBuff,temp,0);
    int angleRaw = (int)(BitConverter::toInt16(receiveBuff,0));
    errorCode = 0;    
    return angleRaw;
}

/* set current angle to zero,then restart device.This operation takes approximately 200 ms.
*/
void AMT21::setZeroPosition()
{
    uint8_t sendBuff[3] = {0x35,0xA5,0x7E};      
    _rs485.write(sendBuff,3);
}

/* checksum calculation
* @param[in] *data received data array
* @return true:correct false:invalid
*/
bool AMT21::checkBits(uint8_t *data)
{
    bool odd = getBit(data[0],1);
    bool even = getBit(data[0],0);
    
    for(int i=1;i<4;i++)
    {
        odd = odd^getBit(data[0],i*2+1); 
        even = even^getBit(data[0],i*2);
    }
    for(int i=0;i<3;i++)
    {
        odd = odd^getBit(data[1],i*2+1); 
        even = even^getBit(data[1],i*2);
    }  

    odd = !odd;
    even = !even;
    if(odd == getBit(data[1],7) && even == getBit(data[1],6))
    {
        return true;
    }
    else
    {
        return false;
    }   
}

/* get specific bit of byte
* @param[in] byte input byte
* @param[in] index index of bit
* @return 1:true 0:false
*/

bool AMT21::getBit(uint8_t byte,int index)
{
    uint8_t result = (byte & ((uint8_t)0x01 << index)) >> index;
    if(result == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
