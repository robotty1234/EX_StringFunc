#include <EX_StringFunc.h>

void setup() {
  Serial.begin(9600);

  Serial.println("Please enter a string");
  Serial.println("If you type 'int:x' (x = type int value) only x is returned");
  Serial.println("If you type 'float:x' (x = type float value) only x is returned");
  Serial.println("If you type 'double:x' (x = type double value) only x is returned");
  Serial.println("If you type 'boolean:x' (x = 'true' or 'false') only x is returned");
  Serial.println("If you type 'string:x' (x = string) only x is returned");
  Serial.println("If none of the above apply, the entered string will be returned");
}

void loop() {
  if(Serial.available()){
    //If 'mark' is not set to true, the string will be returned before the line break
    String s = readStringQ(Serial,true,'\n');
    //Remove '\n'
    s.remove(s.length()-1);
    if(s.indexOf("int:") > -1){
      //test splitToInt
      int i = splitToInt(s, ':');
      Serial.print(i);
      Serial.println(" (type:int)");
    }else if(s.indexOf("float:") > -1){
      //test splitToFloat
      float f = splitToFloat(s, ':');
      Serial.print(f);
      Serial.println(" (type:float)");
    }else if(s.indexOf("double:") > -1){
      //test splitToDouble
      double d = splitToDouble(s, ':');
      Serial.print(d);
      Serial.println(" (type:double)");
    }else if(s.indexOf("boolean:") > -1){
      //test splitToBoolean
      boolean b = splitToBoolean(s, ':');
      if(b == true){
        Serial.print("true");
      }else if(b == false){
        Serial.print("false");
      }
      Serial.println(" (type:boolean)");
    }else if(s.indexOf("string:") > -1){
      //test splitToStr
      String str = splitToStr(s, ':');
      Serial.print(str);
      Serial.println(" (type:String)");
    }else{
      Serial.println(s);
    }
  }
}
