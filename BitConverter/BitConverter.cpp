/**
 * @file BitConverter.cpp
 * @brief BitConverter class library 
 * @author K.Ogasawara
 * @date 2017/11/22
 */


#include "BitConverter.hpp"

/**
* @brief 入力配列のstartIndexから２バイトを読み取ってint16_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る先頭位置
* @return 変換されたデータ
*/ 
int16_t BitConverter::toInt16(uint8_t *array,int startIndex)
{
    union un_temp{
        int16_t data;
        uint8_t byte[2];
    }temp;
    for(int i=0;i<2;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから２バイトを読み取ってuint16_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る先頭位置
* @return 変換されたデータ
*/ 
uint16_t BitConverter::toUint16(uint8_t *array,int startIndex)
{
    union un_temp{
        uint16_t data;
        uint8_t byte[2];
    }temp;
    for(int i=0;i<2;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから4バイトを読み取ってint32_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/ 
int32_t BitConverter::toInt32(uint8_t *array,int startIndex)
{
    union un_temp{
        int32_t data;
        uint8_t byte[4];
    }temp;
    for(int i=0;i<4;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
    
}

/**
* @brief 入力配列のstartIndexから2ワードを読み取ってint32_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/ 
int32_t BitConverter::toInt32(uint16_t *array,int startIndex)
{
    union un_temp{
        int32_t data;
        uint16_t word[2];
    }temp;
    for(int i=0;i<2;i++){
        temp.word[i] = array[startIndex+i];
    }
    return temp.data;
    
}

/**
* @brief 入力配列のstartIndexから2ワードを読み取ってuint32_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/ 
uint32_t BitConverter::toUint32(uint8_t *array,int startIndex)
{
    union un_temp{
        uint32_t data;
        uint8_t byte[4];
    }temp;
    for(int i=0;i<4;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから2ワードを読み取ってuint32_t型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/
uint32_t BitConverter::toUint32(uint16_t *array,int startIndex)
{
    union un_temp{
        uint32_t data;
        uint16_t word[2];
    }temp;
    for(int i=0;i<2;i++){
        temp.word[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから4バイトを読み取ってfloat型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/
float BitConverter::toFloat(uint8_t *array,int startIndex)
{
    union un_temp{
        float data;
        uint8_t byte[4];
    }temp;
    for(int i=0;i<4;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから2ワードを読み取ってfloat型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/
float BitConverter::toFloat(uint16_t *array,int startIndex)
{
    union un_temp{
        float data;
        uint16_t word[2];
    }temp;
    for(int i=0;i<2;i++){
        temp.word[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから８バイトを読み取ってdouble型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/
double BitConverter::toDouble(uint8_t *array,int startIndex)
{
    union un_temp{
        double data;
        uint8_t byte[8];
    }temp;
    for(int i=0;i<8;i++){
        temp.byte[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief 入力配列のstartIndexから4ワードを読み取ってdouble型に変換
* @param[in] *array 入力配列
* @param[in] startIndex 入力配列を読み取る位置
* @return 変換されたデータ
*/
double BitConverter::toDouble(uint16_t *array,int startIndex)
{
    union un_temp{
        double data;
        uint16_t word[4];
    }temp;
    for(int i=0;i<4;i++){
        temp.word[i] = array[startIndex+i];
    }
    return temp.data;
}

/**
* @brief int16_t型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数2)
* @param[in] value 入力データ
*/        
void BitConverter::toArray(uint8_t *array,int16_t value,int startIndex)
{
    union un_temp{
        int16_t data;
        uint8_t byte[2];
    }temp;
    temp.data = value;
    for(int i=0;i<2;i++){
      array[i+startIndex] = temp.byte[i];
    }
}

/**
* @brief uint16_t型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数2)
* @param[in] value 入力データ
*/ 
void BitConverter::toArray(uint8_t *array,uint16_t value,int startIndex)
{
    union un_temp{
        uint16_t data;
        uint8_t byte[2];
    }temp;
    temp.data = value;
    for(int i=0;i<2;i++){
      array[i+startIndex] = temp.byte[i];
    }
}

/**
* @brief int32_t型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数4)
* @param[in] value 入力データ
*/ 
void BitConverter::toArray(uint8_t *array,int32_t value,int startIndex)
{
    union un_temp{
        int32_t data;
        uint8_t byte[4];
    }temp;
    temp.data = value;
    for(int i=0;i<4;i++){
      array[i+startIndex] = temp.byte[i];
    }
}

/**
* @brief int32_t型データをuint16_t型配列に変換
* @param[out] *array 変換された配列(要素数2)
* @param[in] value 入力データ
*/ 
void BitConverter::toArray(uint16_t *array,int32_t value,int startIndex)
{
    union un_temp{
        int32_t data;
        uint16_t word[2];
    }temp;
    temp.data = value;
    for(int i=0;i<2;i++){
      array[i+startIndex] = temp.word[i];
    }
}

/**
* @brief uint32_t型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数4)
* @param[in] value入力データ
*/
void BitConverter::toArray(uint8_t *array,uint32_t value,int startIndex)
{
    union un_temp{
        uint32_t data;
        uint8_t byte[4];
    }temp;
    temp.data = value;
    for(int i=0;i<4;i++){
      array[i+startIndex] = temp.byte[i];
    }
}

/**
* @brief uint32_t型データをuint16_t型配列に変換
* @param[out] *array 変換された配列(要素数2)
* @param[in] value 入力データ
*/
void BitConverter::toArray(uint16_t *array,uint32_t value,int startIndex)
{
    union un_temp{
        uint32_t data;
        uint8_t word[2];
    }temp;
    temp.data = value;
    for(int i=0;i<2;i++){
      array[i+startIndex] = temp.word[i];
    }
}

/**
* @brief float型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数4)
* @param[in] value 入力データ
*/
void BitConverter::toArray(uint8_t *array,float value,int startIndex)
{
    union un_temp{
        float data;
        uint8_t byte[4];
    }temp;
    temp.data = value;
    for(int i=0;i<4;i++){
      array[i+startIndex] = temp.byte[i];
    }
}

/**
* @brief float型データをuint16_t型配列に変換
* @param[out] *array 変換された配列(要素数2)
* @param[in] value 入力データ
*/
void BitConverter::toArray(uint16_t *array,float value,int startIndex)
{
    union un_temp{
        float data;
        uint16_t word[2];
    }temp;
    temp.data = value;
    for(int i=0;i<2;i++){
      array[i+startIndex] = temp.word[i];
    }
}

/**
* @brief double型データをuint8_t型配列に変換
* @param[out] *array 変換された配列(要素数8)
* @param[in] value 入力データ
*/
void BitConverter::toArray(uint8_t *array,double value,int startIndex)
{
    union un_temp{
        double data;
        uint8_t byte[8];
    }temp;
    temp.data = value;
    for(int i=0;i<8;i++){
      array[i+startIndex] = temp.byte[i];
    }    
}

/**
* @brief double型データをuint16_t型配列に変換
* @param[out] *array 変換された配列(要素数4)
* @param[in] value 入力データ
*/
void BitConverter::toArray(uint16_t *array,double value,int startIndex)
{
    union un_temp{
        double data;
        uint16_t word[4];
    }temp;
    temp.data = value;
    for(int i=0;i<4;i++){
      array[i+startIndex] = temp.word[i];
    }
}

