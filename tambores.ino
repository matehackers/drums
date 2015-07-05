#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define LED 13   		// LED pin on Arduino board
const int knockSensor = A0;	// the piezo is connected to analog pin 0
const int threshold = 100;  	// threshold value to decide when the detected sound is a knock or not

int sensorReading = 0;      // variable to store the value read from the sensor pin           
int statePin = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  MIDI.begin(4);            	// Launch MIDI with default options
				// input channel is set to 4

  
  /* Now the problem is that serial port at the computer is only
     able to read serial data at 'standard' baud rates. MIDI baud rate
     that Arduino MIDI library is using, is not one of these.
     One way of fixing this is to edit line 54 of file MIDI.h and set
     Arduino MIDI library to use some other baud rate.
    
     However, one can just simply change the baud rate
     of serial line to some standard baud rate by calling Serial.begin(int)
     immediately after calling MIDI.begin(int). Here we set the speed
     to default baud rate of ttymidi, 115200! This is all you need to
     remember to do if you want to read the data with ttymidi running
     on your computer.  
   */
  Serial.begin(115200);
}




void loop() {

  sensorReading = analogRead(knockSensor);     

  if (sensorReading >= threshold) {

    statePin = !statePin;

    digitalWrite(LED, statePin);
    
    digitalWrite(LED,HIGH);     // Blink the LED
    MIDI.sendNoteOn(35,127,10);  // Send a drum bass note (pitch 42, velo 127 on channel 1)
    delay(100);
    MIDI.sendNoteOff(35,0,10);   // Stop the note
    digitalWrite(LED,LOW);    	

  }

    
}

