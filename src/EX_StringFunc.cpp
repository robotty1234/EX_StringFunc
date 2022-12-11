#include "EX_StringFunc.h"

//Convert string after "keyword" to Int type
int splitToInt(String str, char keyword){
  int val = -1;
  int split = 0;
  for(int i=0;i<str.length();i++){
    if(str.charAt(i) == keyword){
      split = i;
    }
  }
  str.remove(0, (split + 1));
  val = str.toInt();
  return val;
}

//Convert string after "keyword" to Float type
float splitToFloat(String str, char keyword){
  float val = -1.0;
  int split = 0;
  for(int i=0;i<str.length();i++){
    if(str.charAt(i) == keyword){
      split = i;
    }
  }
  str.remove(0, (split + 1));
  val = str.toFloat();
  return val;
}

//Convert string after "keyword" to Double type
double splitToDouble(String str, char keyword){
  double val = -1.0;
  int split = 0;
  for(int i=0;i<str.length();i++){
    if(str.charAt(i) == keyword){
      split = i;
    }
  }
  str.remove(0, (split + 1));
  val = str.toDouble();
  return val;
}

//Convert string after "keyword" to Boolean type
boolean splitToBoolean(String str, char keyword){
  int split = 0;
  for(int i=0;i<str.length();i++){
    if(str.charAt(i) == keyword){
      split = i;
    }
  }
  str.remove(0, (split + 1));
  if(str.equalsIgnoreCase("true")){
    return true;
  }else{
    return false;
  }
}

//Returns string after "keyword"
String splitToStr(String str, char keyword){
  int split = 0;
  for(int i=0;i<str.length();i++){
    if(str.charAt(i) == keyword){
      split = i;
    }
  }
  str.remove(0, (split + 1));
  return str;
}

//A function that returns the message received from the serial port as a string of type String
String readStringQ(HardwareSerial &serial, boolean mark = false, char keyword = '\n'){
  String s;
  char c;
  do{
    while(serial.available() <= 0);
    c = serial.read();
    s.concat(String(c));
  }while((mark == false && serial.available() > 0) || (mark == true && c != keyword));
  return s;
}
