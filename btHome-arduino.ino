/*
 * Connect EN pin to 3.3V
 * Set line ending to CR and NL in Serial Monitor
 * Connect Bluetooth RX TX to SoftwareSerial TX RX
 * Restart Arduino
*/

/*
 * Basic Commands
 * AT+NAME=YOURDEVICENAME will change your HC-05 name to YOURDEVICENAME (fill in whatever you like) 
 * AT+RMAAD will release the module from any previous PAIR
 * AT+PSWD=1234 to set the password as 1234 
 */

#define BluetoothRX 9
#define BluetoothTX 10

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(BluetoothTX, BluetoothRX); // RX | TX

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
