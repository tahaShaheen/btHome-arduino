void returnStates() {
  Serial.print("BULB: ");
  if (Sw1State ^ Bluetooth4State)
    Serial.println("ON");
  else
    Serial.println("OFF");

  Serial.print("FAN: ");
  if (Sw2State ^ Bluetooth3State )
    Serial.println("ON");
  else
    Serial.println("OFF");

  Serial.print("SWITCH BOARD: ");
  if (Sw3State ^ Bluetooth2State )
    Serial.println("ON");
  else
    Serial.println("OFF");

  Serial.print("PLUG: ");
  if (Sw4State ^ Bluetooth1State )
    Serial.println("ON");
  else
    Serial.println("OFF");
}
