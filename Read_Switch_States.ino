void readSwitcheStates() {
  //First we save the previous states that the switches had
  //this will come in handy because previous states will be compared to the staes now
  //if both are the same, no update has taken place and there is nothing to do
  Sw_energySaver_StatePrevious = Sw_energySaver_State;
  Sw_fan_StatePrevious = Sw_fan_State;
  Sw_switchBoard2_StatePrevious = Sw_switchBoard2_State;
  Sw_socket_StatePrevious = Sw_socket_State;

  //Current states read
  Sw_energySaver_State = !(digitalRead(Swicth_energySaver));
  Sw_fan_State = !(digitalRead(Switch_fan));
  Sw_switchBoard2_State = !(digitalRead(Switch_switchBoard2));
  Sw_socket_State = !(digitalRead(Switch_socket));

  //This part of the code is executed if any change in the states is detected
  if ((Sw_energySaver_State != Sw_energySaver_StatePrevious) || (Sw_fan_State != Sw_fan_StatePrevious) || (Sw_switchBoard2_State != Sw_switchBoard2_StatePrevious) || (Sw_socket_State != Sw_socket_StatePrevious)) {
    delay(400); //delay to prevent debouncing
    updateStates();
  }
}
