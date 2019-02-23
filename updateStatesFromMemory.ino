void updateStatesFromMemory() {
  if (Sw1StateMem)
    digitalWrite(RELAY_4, LOW);
  else
    digitalWrite(RELAY_4, HIGH);
  if (Sw2StateMem)
    digitalWrite(RELAY_3, LOW);
  else
    digitalWrite(RELAY_3, HIGH);
  if (Sw3StateMem)
    digitalWrite(RELAY_2, LOW);
  else
    digitalWrite(RELAY_2, HIGH);
  if (Sw4StateMem)
    digitalWrite(RELAY_1, LOW);
  else
    digitalWrite(RELAY_1, HIGH);
}

