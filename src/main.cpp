/*
  Sketch 21.1.1
  Infrared Remote Control orginally by FREENOVE.COM
  Modified May 9th 2025 by David Elmo Ross
  Commented out lines 1614-1622 of file
  .PIO/libdeps/esp-wrover-kit/IRremote/src/IRRECEIVE.hpp
  (so that deprecated message did NOT come to screen).

  Description:  When the IR RECEIVER is connected to PIN 2,
                and you use a 10K PullUp resistor to 3.3V,
                every time you push a button on the IR REMOTE
                it will show a unique HEX code on the sreen
                associated with that BUTTON. Please make a chart
                that has BUTTON and HEX CODE.
*/

#include "arduino.h"                                // add arduino library
#include <IRremote.h>                               // add IRremote library

int RECV_PIN = 2;                                   // Infrared receiver pin
IRrecv irrecv(RECV_PIN);                            // Create a class object used to receive class
decode_results results;                             // Create a decoding results class object

void setup()
{
  Serial.begin(9600);                               // Initialize serial port to 9600
  printf("\e[2;1H");                                // set cursor to (2,1) on screen
  printf("\e[2J");                                  // clear PC screen
  printf("Ir Receiver is ready!\n");                // Print "Ir Receiver is ready!"
  irrecv.enableIRIn();                              // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results))                      // if Ir Value has been received
  {  
    Serial.println(results.value, HEX);             // Print out the decoded results in HEX
    irrecv.resume();                                // Receive the next value
  }
  delay(500);                                       // delay 0.5 seconds
}
