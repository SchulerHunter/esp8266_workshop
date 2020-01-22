// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>
 
// Define sensor pin
const int RECV_PIN = 4;
 
// Define LED pin constants
const int bluePin = 8; 
const int greenPin = 7;
const int yellowPin = 6; 
const int redPin = 5;
 
// Define integer to remember toggle state
int togglestate = 0;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 
 
void setup(){
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}
 
 
void loop(){
    if (irrecv.decode(&results)){
 
        switch(results.value){
          case 0x20DF4EB1: //Blue Keypad Button
        // Turn on LED for 2 Seconds
        digitalWrite(bluePin, HIGH);
        delay(2000);
        digitalWrite(bluePin, LOW);
        break;

          case 0x20DF8E71: //Green Keypad Button
        // Turn on LED for 2 Seconds
        digitalWrite(greenPin, HIGH);
        delay(2000);
        digitalWrite(greenPin, LOW);
        break;
        
          case 0x20DFC639: //Yellow Keypad Button
        // Turn on LED for 2 Seconds
        digitalWrite(yellowPin, HIGH);
        delay(2000);
        digitalWrite(yellowPin, LOW);
        break;
        
          case 0x20DF8679: //Red Keypad Button
        // Turn on LED for 2 Seconds
        digitalWrite(redPin, HIGH);
        delay(2000);
        digitalWrite(redPin, LOW);
        break;
        
      /*    case 0xFE8A75: //Yellow Keypad Button
        // Toggle LED On or Off
        if(togglestate==0){
        digitalWrite(yellowPin, HIGH);
        togglestate=1;
        }
        else {
        digitalWrite(yellowPin, LOW);
        togglestate=0;
        }
        break;
        */
    }
    irrecv.resume(); 
  }
 
}
