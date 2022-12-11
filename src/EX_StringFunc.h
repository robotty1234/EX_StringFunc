#ifndef _EX_STRINGFUNC_H_
#define _EX_STRINGFUNC_H_

#include <Arduino.h>

//Convert string after "keyword" to Int type
int splitToInt(String str, char keyword);
//Convert string after "keyword" to Float type
float splitToFloat(String str, char keyword);
//Convert string after "keyword" to Double type
double splitToDouble(String str, char keyword);
//Convert string after "keyword" to boolean type
boolean splitToBoolean(String str, char keyword);
//Convert string after "keyword" to String type
String splitToStr(String str, char keyword);
//A function that returns the message received from the serial port as a string of type String
String readStringQ(HardwareSerial &serial, boolean mark = false, char keyword = '\n');

#endif
