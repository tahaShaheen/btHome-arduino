/*
   Made by Taha Shaheen
   Start Date: 22nd Aug 2017
   End Date: 28th Aug 2017

   This version supports updating based on latest input
   be it from BT or Switch Board

*/

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
boolean change;

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

  Sw1State = false;
  Sw2State = false;
  Sw3State = false;
  Sw4State = false;

  Bluetooth1State = false;
  Bluetooth2State = false;
  Bluetooth3State = false;
  Bluetooth4State = false;

  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);
}

void loop() {
  readSwitcheStates();
  if (change == true)
    updateStates();
  bluetoothCheck();
}

void bluetoothCheck() {
  if (stringComplete) {
    Serial.println(inputString);
    switch (inputString.toInt()) {
      case 1:
        Bluetooth4State = !Bluetooth4State;
        break;
      case 2:
        Bluetooth3State  = !Bluetooth3State;
        break;
      case 3:
        Bluetooth2State  = !Bluetooth2State;
        break;
      case 4:
        Bluetooth1State  = !Bluetooth1State;
        break;
      default:
        returnStates();
    }
    updateStates();
    inputString = "";
    stringComplete = false;
  }
}
void readSwitcheStates() {
  Sw1StatePrevious = Sw1State;
  Sw2StatePrevious = Sw2State;
  Sw3StatePrevious = Sw3State;
  Sw4StatePrevious = Sw4State;
  Sw1State = !(digitalRead(Switch_01));
  Sw2State = !(digitalRead(Switch_02));
  Sw3State = !(digitalRead(Switch_03));
  Sw4State = !(digitalRead(Switch_04));
  if ((Sw1State != Sw1StatePrevious) || (Sw3State != Sw3StatePrevious) || (Sw3State != Sw3StatePrevious) || (Sw4State != Sw4StatePrevious))
    change = true;
}

void updateStates() {
  if (Sw1State ^ Bluetooth4State)
    digitalWrite(RELAY_4, LOW);
  else
    digitalWrite(RELAY_4, HIGH);
  if (Sw2State ^ Bluetooth3State )
    digitalWrite(RELAY_3, LOW);
  else
    digitalWrite(RELAY_3, HIGH);
  if (Sw3State ^ Bluetooth2State )
    digitalWrite(RELAY_2, LOW);
  else
    digitalWrite(RELAY_2, HIGH);
  if (Sw4State ^ Bluetooth1State )
    digitalWrite(RELAY_1, LOW);
  else
    digitalWrite(RELAY_1, HIGH);
}

void returnStates() {
  byte States = 0b0000000;
  if (Sw1State ^ Bluetooth4State)
    States |= 0b10000000;
  else
    States &= 0b01111111;

  if (Sw2State ^ Bluetooth3State )
    States |= 0b01000000;
  else
    States &= 0b10111111;

  if (Sw3State ^ Bluetooth2State )
    States |= 0b00100000;
  else
    States &= 0b11011111;

  if (Sw4State ^ Bluetooth1State )
    States |= 0b00010000;
  else
    States &= 0b11101111;

    Serial.println(States);
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
