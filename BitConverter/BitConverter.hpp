#ifndef _BITCONVERTER_HPP_
#define _BITCONVERTER_HPP_


#ifndef uint8_t 
#define uint8_t unsigned char
#endif

#ifndef int16_t 
#define int16_t short
#endif

#ifndef uint16_t 
#define uint16_t unsigned short
#endif

#ifndef int32_t 
#define int32_t int
#endif

#ifndef uint32_t 
#define uint32_t unsigned int
#endif

class BitConverter
{
    public:
        static int16_t toInt16(uint8_t *array,int startIndex=0);
        
        static uint16_t toUint16(uint8_t *array,int startIndex=0);
        
        static int32_t toInt32(uint8_t *array,int startIndex=0);
        static int32_t toInt32(uint16_t *array,int startIndex=0);
        
        static uint32_t toUint32(uint8_t *array,int startIndex=0);
        static uint32_t toUint32(uint16_t *array,int startIndex=0);
        
        static float toFloat(uint8_t *array,int startIndex=0);
        static float toFloat(uint16_t *array,int startIndex=0);
        
        static double toDouble(uint8_t *array,int startIndex=0);
        static double toDouble(uint16_t *array,int startIndex=0);
        
        
        static void toArray(uint8_t *array,int16_t value,int startIndex=0);
        static void toArray(uint8_t *array,uint16_t value,int startIndex=0);
        
        static void toArray(uint8_t *array,int32_t value,int startIndex=0);
        static void toArray(uint16_t *array,int32_t value,int startIndex=0);
        
        static void toArray(uint8_t *array,uint32_t value,int startIndex=0);
        static void toArray(uint16_t *array,uint32_t value,int startIndex=0);
        
        static void toArray(uint8_t *array,float value,int startIndex=0);
        static void toArray(uint16_t *array,float value,int startIndex=0);
        
        static void toArray(uint8_t *array,double value,int startIndex=0);
        static void toArray(uint16_t *array,double value,int startIndex=0);
};
#endif
