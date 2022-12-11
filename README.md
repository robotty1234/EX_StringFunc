# EX_StringFunc
Variables that quickly receive and return a string from the serial port without using readString and variables that return values after a specific character in various types are summarized.
# Introduction to functions
## String readStringQ(HardwareSerial &serial, boolean mark = false, char keyword = '\n')
A function that returns the message received from the serial port as a string of type String.If the mark argument is false (default value), the content obtained by Serial.read() is returned as a String type, but by setting mark to true, the keyword argument (newline character '\n' is set by default) Continue reading the serial port until you get a ) character. Note that it will enter an infinite loop unless it gets the characters for keyword.
```
//When assigning the value from the Hardware Serial to the String type s variable.
//The value "hello\n" is sent to the serial port.
//Results may vary depending on the communication speed.
String s = readStringQ(Serial);
>>s = h
>>s = e
>>s = l
>>s = l
>>s = o
>>s = \n
```
```
//When assigning a value from Hardware Serial to the string type s variable.
//The value "hello\n" is sent to the serial port.
//True is passed to the mark argument.
String s = readStringQ(Serial,true);
>>s = hello
```
```
//When assigning a value from Hardware Serial to the string type s variable.
//The value "helloa" is sent to the serial port.
//True is passed to the mark argument.
//'a' is passed to the keyword argument
String s = readStringQ(Serial,true,'a');
>>s = hello
```
## int splitToInt(String str, char keyword)
Convert string after "keyword" to Int type.Returns -1 if the character passed to keyword does not exist, and 0 if the conversion fails.Converting to Boolean only determines whether it is a "true" character (regardless of uppercase or lowercase).
```
String str = int:10;
int i = splitToInt(str, ':');
>>i = 10
```
```
String str = int:10;
int i = splitToInt(str, ':');
>>i = 0
```
```
String str = int10.0\n;
int i = splitToInt(str, ':');
>>i = -1
```
## float splitToFloat(String str, char keyword)
Convert string after "keyword" to Float type.Returns -1.00 if the character passed to keyword does not exist, and 0.00 if the conversion fails.
```
String str = float:10.0;
float f = splitToFloat(str, ':');
>>f = 10.00
```
```
String str = float:10.0\n;
float f = splitToFloat(str, ':');
>>f = 0.00
```
```
String str = float10.0\n;
float f = splitToFloat(str, ':');
>>f = -1.00
```
## double splitToDouble(String str, char keyword)
Convert string after "keyword" to Double type.Returns -1.00 if the character passed to keyword does not exist, and 0.00 if the conversion fails.
```
String str = double:10.0;
double d = splitToDouble(str, ':');
>>d = 10.00
```
```
String str = double:10.0\n;
double d = splitToDouble(str, ':');
>>d = 0.00
```
```
String str = double10.0\n;
double d = splitToDouble(str, ':');
>>d = -1.00
```
## boolean splitToBoolean(String str, char keyword)
Converts the string after "keyword" to boolean. Returns false if the character passed in keyword does not exist or if the conversion fails.
```
String str = boolean:True;
boolean b = splitToBoolean(str, ':');
>>b = true or 1
```
```
String str = boolean:True\n;
boolean b = splitToBoolean(str, ':');
>>b = false
```
```
String str = booleanTrue\n;
boolean b  = splitToBoolean(str, ':');
>>b = falsee
```
## String splitToStr(String str, char keyword)
Convert string after "keyword" to String type.
```
String str = String:hello;
String s = splitToBoolean(str, ':');
>>s = hello
```
```
String str = String/hello;
String s = splitToBoolean(str, ':');
>>s = String/hello
```
