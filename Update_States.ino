void updateStates() {
  //V4.2 only supports Switch States 
  //and returning states of appliances at Bluetooth command
  //The appliances turn on or off based state changes of Switches

  if (Sw_energySaver_State != Sw_energySaver_StatePrevious)
    digitalWrite(RELAY_energySaver, !digitalRead(RELAY_energySaver));
  else
    digitalWrite(RELAY_energySaver, digitalRead(RELAY_energySaver));

  if ((Sw_fan_State != Sw_fan_StatePrevious))
    digitalWrite(RELAY_fan, !digitalRead(RELAY_fan));
  else
    digitalWrite(RELAY_fan, digitalRead(RELAY_fan));

  if (Sw_switchBoard2_State != Sw_switchBoard2_StatePrevious)
    digitalWrite(RELAY_switchBoard2, !digitalRead(RELAY_switchBoard2));
  else
    digitalWrite(RELAY_switchBoard2, digitalRead(RELAY_switchBoard2));

  if (Sw_socket_State != Sw_socket_StatePrevious)
    digitalWrite(RELAY_socket, !digitalRead(RELAY_socket));
  else
    digitalWrite(RELAY_socket, digitalRead(RELAY_socket));

  returnStates(); //remove this
}
