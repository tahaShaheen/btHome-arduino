/*
   Made by Taha Shaheen
   Start Date: 22nd Aug 2017
   End Date: 28th Aug 2017

   This version supports updating based on latest input
   be it from BT or Switch Board

*/
#include "EEPROM.h"

#define RELAY_1 7
#define RELAY_2 6
#define RELAY_3 5
#define RELAY_4 4

#define Switch_01 A0
#define Switch_02 A1
#define Switch_03 A2
#define Switch_04 A3

String inputString = "";
boolean stringComplete = false;
boolean Sw1State, Sw2State, Sw3State, Sw4State, Sw1StatePrevious, Sw2StatePrevious, Sw3StatePrevious, Sw4StatePrevious;
boolean Bluetooth1State, Bluetooth2State, Bluetooth3State, Bluetooth4State;
boolean Sw1StateMem, Sw2StateMem, Sw3StateMem, Sw4StateMem;
boolean change;
int eepromAddress = 0;
byte States;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");

  inputString.reserve(200);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  pinMode(Switch_01, INPUT_PULLUP);
  pinMode(Switch_02, INPUT_PULLUP);
  pinMode(Switch_03, INPUT_PULLUP);
  pinMode(Switch_04, INPUT_PULLUP);

  EEPROM.write(eepromAddress, 0x0F); //delete after first run
  readSwitchStatesFromMemory();
  Serial.print("Reading from memory:");
  Serial.println(States, BIN);
  updateStatesFromMemory();

  Sw1State = !(digitalRead(Switch_01));
  Sw2State = !(digitalRead(Switch_02));
  Sw3State = !(digitalRead(Switch_03));
  Sw4State = !(digitalRead(Switch_04));

  Bluetooth1State = false;
  Bluetooth2State = false;
  Bluetooth3State = false;
  Bluetooth4State = false;
}

void loop() {
  readSwitchStates();
  if (change == true) {
    updateStates();
    saveSwitchStatesToMemory();
  }
  bluetoothCheck();
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 't' || inChar == '\n') {
      stringComplete = true;
    }
  }
}
