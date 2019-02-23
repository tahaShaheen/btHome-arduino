void updateStates() {
  //V4.3 supports Switch and Bluetooth commands
  //The appliances turn on or off based state changes of Switches or of Bluetooth
  //The OR ensures that it updates at every change in State, whether Bluetooth or Switch

  if ((Sw_energySaver_State != Sw_energySaver_StatePrevious) || (Bluetooth_energySaver_State != Bluetooth_energySaver_StatePrevious))
    digitalWrite(RELAY_energySaver, !digitalRead(RELAY_energySaver));

  if ((Sw_fan_State != Sw_fan_StatePrevious) || (Bluetooth_fan_State != Bluetooth_fan_StatePrevious))
    digitalWrite(RELAY_fan, !digitalRead(RELAY_fan));

  if ((Sw_switchBoard2_State != Sw_switchBoard2_StatePrevious) || (Bluetooth_switchBoard2_State != Bluetooth_switchBoard2_StatePrevious))
    digitalWrite(RELAY_switchBoard2, !digitalRead(RELAY_switchBoard2));

  if ((Sw_socket_State != Sw_socket_StatePrevious) || (Bluetooth_socket_State != Bluetooth_socket_StatePrevious))
    digitalWrite(RELAY_socket, !digitalRead(RELAY_socket));
}
