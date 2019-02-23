void readSwitchStatesFromMemory () {
  States = EEPROM.read(eepromAddress);

  Sw1StateMem = bitRead(8, States);
  Sw2StateMem = bitRead(7, States);
  Sw3StateMem = bitRead(6, States);
  Sw4StateMem = bitRead(5, States);
}

