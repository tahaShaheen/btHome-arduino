void returnStates() {
  //The first nibble of the byte "States" reflects the current state of the devices
  //The byte "States" does not updated regualrly because it does not need to be

  if (!digitalRead(RELAY_energySaver))
    States |= 0b10000000;
  else
    States &= 0b01111111;

  if (!digitalRead(RELAY_fan))
    States |= 0b01000000;
  else
    States &= 0b10111111;

  if (!digitalRead(RELAY_switchBoard2))
    States |= 0b00100000;
  else
    States &= 0b11011111;

  if (!digitalRead(RELAY_socket))
    States |= 0b00010000;
  else
    States &= 0b11101111;

  Serial.println(States, BIN);
  //The binary is easier to interpret
  //1 is ON
  //0 is OFF
}
