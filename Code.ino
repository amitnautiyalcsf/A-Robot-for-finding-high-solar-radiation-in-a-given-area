 int motorPin1 = 2; // pin 2 on L293D IC
int motorPin2 = 3; // pin 7 on L293D IC
int motorPin3 = 4; // pin 10 on L293D IC
int motorPin4 = 5; // pin 15 on L293D IC
int motorPin5 = 6; // pin 2 on L293D IC
int motorPin6 = 7; // pin 7 on L293D IC
int motorPin7 = 8; // pin 10 on L293D IC
int motorPin8 = 9; // pin 15 on L293D IC

const int buttonPin[] = {A0, A1, A2, A3 };     // the number of the pushbutton pins
 // variables will change:
int buttonState = 0;   

#include <SD.h>
const int chipSelect = 10;

int analogPin = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K) -see text!
float R2 = 10000.0; // resistance of R2 (10K) - see text!
int value = 0;  

void setup() {
  // initialize serial communication at 9600 bits per second:
  
 Serial.begin(9600);
 Serial.print("Initializing SD card...");
 // make sure that the default chip select pin is set to
 // output, even if you don't use it:
 pinMode(10, OUTPUT);
 // see if the card is present and can be initialized:
 if (!SD.begin(chipSelect)) {
 Serial.println("Card failed, or not present");
 // don't do anything more:
 return;
 }
 Serial.println("card initialized.");
    
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    pinMode(motorPin7, OUTPUT);
    pinMode(motorPin8, OUTPUT);
  

   for(int x=0; x<4; x++)
   {
    pinMode(buttonPin[x], INPUT_PULLUP); 
  }  

}

void loop() 
    {
      {
         // read the value at analog input
   value = analogRead(analogPin);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
}
String dataString = "";
 // read three sensors and append to the string:

 dataString += String(vin);
 if (analogPin < 2) {
 dataString += ",";

 }
   
  
 File dataFile = SD.open("datalog.txt", FILE_WRITE);
 if (dataFile) {
 dataFile.println(dataString);
 delay(2000);
 dataFile.close();
 Serial.println(dataString);
 delay(2000);
 }
 else {
 Serial.println("error opening datalog.txt");
 }
 

      
  // read the state of the keypad value:
  for(int x=0; x<4; x++)
  {
    //signifying the state of which the button is in by reading the appropriate pin #
    buttonState = digitalRead(buttonPin[x]);

    // check if the pushbutton on the keypad is pressed.
    // if it is, the buttonState is LOW:
    if (buttonState == LOW && buttonPin[x] == A0) {  
      
      
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW);
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(5000);
   
   digitalWrite(2, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, LOW);
   delay(5000);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
     delay(70000);
    }

     if (buttonState == LOW && buttonPin[x] == A1) {  
      
      
    
  
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(5000);
   
   digitalWrite(2, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, LOW);
   delay(5000);
    }


     if (buttonState == LOW && buttonPin[x] == A2) {  
      
      
    
  
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(5000);
   
   digitalWrite(2, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, LOW);
   delay(5000);


    }




 if (buttonState == LOW && buttonPin[x] == A3) {  
      
      
    
  
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(5000);
   
   digitalWrite(2, LOW);
   digitalWrite(4, LOW);
   digitalWrite(6, LOW);
   digitalWrite(8, LOW);
   delay(5000);


    }
    
  }
  
      }
    }
