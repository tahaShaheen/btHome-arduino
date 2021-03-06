void bluetoothCheck() {

  //Serial.println(inputString); //commented because it was returned evertime a command was sent, this was disturbing when returnStates was called via bluetooth

  Bluetooth_energySaver_StatePrevious = Bluetooth_energySaver_State;
  Bluetooth_fan_StatePrevious = Bluetooth_fan_State;
  Bluetooth_switchBoard2_StatePrevious = Bluetooth_switchBoard2_State;
  Bluetooth_socket_StatePrevious = Bluetooth_socket_State;

  switch (inputString.toInt()) {
    //This function assumes that the user knows the current state of the device
    //and wishes to change it.
    //A command, one for each device, can be issued by the user
    //This command flips the state
    case 1:
      Bluetooth_energySaver_State = !Bluetooth_energySaver_State;
      updateStates();
      Bluetooth_energySaver_StatePrevious = Bluetooth_energySaver_State;
      break;
    case 2:
      Bluetooth_fan_State  = !Bluetooth_fan_State;
      updateStates();
      Bluetooth_fan_StatePrevious = Bluetooth_fan_State;
      break;
    case 3:
      Bluetooth_switchBoard2_State  = !Bluetooth_switchBoard2_State;
      updateStates();
      Bluetooth_switchBoard2_StatePrevious = Bluetooth_switchBoard2_State;
      break;
    case 4:
      Bluetooth_socket_State  = !Bluetooth_socket_State;
      updateStates();
      Bluetooth_socket_StatePrevious = Bluetooth_socket_State;
      break;
    default:
      returnStates(); //This returns the States to the user
  }
}


