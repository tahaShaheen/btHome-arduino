void updateStates() {
  if (Sw1State ^ Bluetooth4State)
    digitalWrite(RELAY_4, LOW);
  else
    digitalWrite(RELAY_4, HIGH);
  if (Sw2State ^ Bluetooth3State )
    digitalWrite(RELAY_3, LOW);
  else
    digitalWrite(RELAY_3, HIGH);
  if (Sw3State ^ Bluetooth2State )
    digitalWrite(RELAY_2, LOW);
  else
    digitalWrite(RELAY_2, HIGH);
  if (Sw4State ^ Bluetooth1State )
    digitalWrite(RELAY_1, LOW);
  else
    digitalWrite(RELAY_1, HIGH);
}
