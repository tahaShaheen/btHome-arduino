void bluetoothCheck() {

  Serial.println(inputString);

  switch (inputString.toInt()) {
    //This command only return to the user the States of the appliances
    default:
      returnStates(); //This returns the States to the user
  }
}


