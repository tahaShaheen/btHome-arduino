void updateStates() {
  //The XOR is used because it cleverly helps in only
  //updating if a state has changed

  //If both want it OFF, it is OFF
  //If one wants it ON, it is ON
  //If both say they want it ON, means that it was already ON and the one now requesting to turn it ON, actually wants to turn it OFF
  
  if (Sw_energySaver_State ^ Bluetooth_energySaver_State)
    digitalWrite(RELAY_energySaver, LOW);
  else
    digitalWrite(RELAY_energySaver, HIGH);
  if (Sw_fan_State ^ Bluetooth_fan_State )
    digitalWrite(RELAY_fan, LOW);
  else
    digitalWrite(RELAY_fan, HIGH);
  if (Sw_switchBoard2_State ^ Bluetooth_switchBoard2_State )
    digitalWrite(RELAY_switchBoard2, LOW);
  else
    digitalWrite(RELAY_switchBoard2, HIGH);
  if (Sw_socket_State ^ Bluetooth_socket_State )
    digitalWrite(RELAY_socket, LOW);
  else
    digitalWrite(RELAY_socket, HIGH);
}
