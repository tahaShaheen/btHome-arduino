void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 't' /*from input from Bluetooth*/ || inChar == '\n'/*for input from SerialMonitor PC*/) {
      //stringComplete = true;
      bluetoothCheck(); //Bluetooth updating function called
      inputString = ""; //emptying memory after work is done
      //stringComplete = false; //
    }
  }
}
