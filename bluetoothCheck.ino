void bluetoothCheck() {
  if (stringComplete) {
    Serial.println(inputString);
    switch (inputString.toInt()) {
      case 1:
        Bluetooth4State = !Bluetooth4State;
        change = true;
        break;
      case 2:
        Bluetooth3State  = !Bluetooth3State;
        change = true;
        break;
      case 3:
        Bluetooth2State  = !Bluetooth2State;
        change = true;
        break;
      case 4:
        Bluetooth1State  = !Bluetooth1State;
        change = true;
        break;
      default:
        returnStates();
        change = false;
    }
    inputString = "";
    stringComplete = false;
  }
}

