/* JoyStick module transceiver code
 - CONNECTIONS: nRF24L01 Modules See:
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
   
   Default Button Pins: 
   Up     - pin 2
   Right  - pin 3
   Down   - pin 4
   Left   - pin 5
   - 
   Analog Joystick module
   GND    to Arduino GND
   VCC    to Arduino +5V
   X Pot  to Arduino A6
   Y Pot  to Arduino A7
/*-----( Import needed libraries )-----*/

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN  8
#define CSN_PIN 9
#define xAxis 20     // A6 for Arduino UNO
#define yAxis 21     // A7 for Arduino UNO

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

/*-----( Declare Variables )-----*/
int joystick[6];  // 6 element array holding Joystick reading and 4 buttons

int buttonUp    = 2;
int buttonRight = 3;
int buttonDown  = 4;
int buttonLeft  = 5;


void setup() {

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.stopListening();
  
  //declare pinMode for all buttons and initial state
  pinMode(buttonUp,INPUT_PULLUP);
  pinMode(buttonRight,INPUT_PULLUP);
  pinMode(buttonDown,INPUT_PULLUP);
  pinMode(buttonLeft,INPUT_PULLUP);
  
  digitalWrite(buttonUp,LOW);
  digitalWrite(buttonRight,LOW);
  digitalWrite(buttonDown,LOW);
  digitalWrite(buttonLeft,LOW);

}

void loop() {
  
  joystick[0] = analogRead(xAxis);
  joystick[1] = analogRead(yAxis);
  joystick[2] = digitalRead(buttonUp);
  joystick[3] = digitalRead(buttonRight);
  joystick[4] = digitalRead(buttonDown);
  joystick[5] = digitalRead(buttonLeft);
  
  radio.write( joystick, sizeof(joystick) );
  delay(20);

      Serial.print("X = ");
      Serial.print(analogRead(xAxis));
      Serial.print(" Y = ");  
      Serial.print(analogRead(yAxis));
      Serial.print(" Up = "); 
      Serial.print(digitalRead(buttonUp));
      Serial.print(" Right = "); 
      Serial.print(digitalRead(buttonRight));
      Serial.print(" Down = "); 
      Serial.print(digitalRead(buttonDown));
      Serial.print(" Left = "); 
      Serial.println(digitalRead(buttonLeft));

}
