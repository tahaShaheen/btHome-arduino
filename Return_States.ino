void returnStates() {
  //The lower nibble of the byte "States" reflects the current state of the devices
  //The byte "States" does not updated regualrly because it does not need to be

  byte States = 0b11111111;

  if (!digitalRead(RELAY_energySaver))
    States |= 0b00001000;
  else
    States &= 0b11110111;

  if (!digitalRead(RELAY_fan))
    States |= 0b00000100;
  else
    States &= 0b11111011;

  if (!digitalRead(RELAY_switchBoard2))
    States |= 0b00000010;
  else
    States &= 0b11111101;

  if (!digitalRead(RELAY_socket))
    States |= 0b00000001;
  else
    States &= 0b11111110;

  Serial.print("t");
  Serial.print(States, BIN);
  Serial.print("t");
  //The binary is easier to interpret
  //1 is ON
  //0 is OFF
}
