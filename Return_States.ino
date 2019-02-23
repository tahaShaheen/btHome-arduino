void returnStates() {
  //The first nibble of the byte "States" reflects the current state of the devices
  //This function employes the same XOR operator to find out what states the updateStates function would assign to each device
  //This is a localized function that only the Bluetooth command can call. It is independant of the regualr flow of the "loop"
  //The byte "States" does not updated regualrly because it does not need to be

  byte States = 0b0000000;

  if (Sw_socket_State ^ Bluetooth_socket_State)
    States |= 0b00010000; 
  else
    States &= 0b11101111;
    
  if (Sw_switchBoard2_State ^ Bluetooth_switchBoard2_State )
    States |= 0b00100000;
  else
    States &= 0b11011111;

  if (Sw_fan_State ^ Bluetooth_fan_State )
    States |= 0b01000000;
  else
    States &= 0b10111111;

  if (Sw_energySaver_State ^ Bluetooth_energySaver_State )
    States |= 0b10000000;
  else
    States &= 0b01111111;

  Serial.println(States, BIN);
  //The binary is easier to interpret
  //1 is ON
  //0 is OFF
}


