void readSwitchStates() {


  Sw1StatePrevious = Sw1State;
  Sw2StatePrevious = Sw2State;
  Sw3StatePrevious = Sw3State;
  Sw4StatePrevious = Sw4State;

  Sw1State = !(digitalRead(Switch_01));
  Sw2State = !(digitalRead(Switch_02));
  Sw3State = !(digitalRead(Switch_03));
  Sw4State = !(digitalRead(Switch_04));

  if ((Sw1State != Sw1StatePrevious) || (Sw3State != Sw3StatePrevious) || (Sw3State != Sw3StatePrevious) || (Sw4State != Sw4StatePrevious))
    change = true;
  else
    change = false;
}
