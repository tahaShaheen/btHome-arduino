void saveSwitchStatesToMemory () {
  
  if (Sw1State)
    States |= 0b10000000;
  else
    States &= 0b01111111;
  if (Sw2State)
    States |= 0b01000000;
  else
    States &= 0b10111111;
  if (Sw3State)
    States |= 0b00100000;
  else
    States &= 0b11011111;
  if (Sw4State)
    States |= 0b00010000;
  else
    States &= 0b11101111;

  EEPROM.update(eepromAddress, States);
  Serial.print("Saved to memory:");
  Serial.println(States, BIN);
}
