/*
   Made by Taha Shaheen
   Start Date: 24thOct2017
   End Date:

   This version is where all code is rewritten to stamp out errors
   This is V4.3.
   It only supports Switch Inpts.
   It also supports returning appliance state data to the user
   The appliances can be switched via bluetooth commands as well

   There is no memory. Initial startup positions always OFF are not based on Switch Board positions.
   Switching happens at switch state updates
*/

#define RELAY_socket 7   //Socket
#define RELAY_switchBoard2 6   //SwitchBoard2
#define RELAY_fan 5   //Fan
#define RELAY_energySaver 4   //Energy Saver

#define Swicth_energySaver A0    //Energy Saver
#define Switch_fan A1    //Fan
#define Switch_switchBoard2 A2    //SwitchBoard2
#define Switch_socket A3    //Socket

boolean Sw_energySaver_State, Sw_fan_State, Sw_switchBoard2_State, Sw_socket_State,
        Sw_energySaver_StatePrevious, Sw_fan_StatePrevious, Sw_switchBoard2_StatePrevious, Sw_socket_StatePrevious;
boolean change = false;

boolean Bluetooth_socket_State, Bluetooth_switchBoard2_State, Bluetooth_fan_State, Bluetooth_energySaver_State,
        Bluetooth_socket_StatePrevious, Bluetooth_switchBoard2_StatePrevious, Bluetooth_fan_StatePrevious, Bluetooth_energySaver_StatePrevious;

String inputString = "";
boolean stringComplete = false;


void setup() {
  Serial.begin(9600);
//  Serial.println("Ready...");

  inputString.reserve(200);   //Reserved for Serial Event input characters

  //All relay pins made output
  pinMode(RELAY_socket, OUTPUT);
  pinMode(RELAY_switchBoard2, OUTPUT);
  pinMode(RELAY_fan, OUTPUT);
  pinMode(RELAY_energySaver, OUTPUT);

  //Initailly all Relays turned off. Relays are ACTIVE LOW. (The opto-coupler is ACTIVE LOW)
  digitalWrite(RELAY_socket, HIGH);
  digitalWrite(RELAY_switchBoard2, LOW); /*This one is turned ON by default because 
                                           (a)It is a switch board that should always be ON, 
                                           (b)It serves as a diagnostic tool by turning ON as soon as the setup is reset */
  digitalWrite(RELAY_fan, HIGH);
  digitalWrite(RELAY_energySaver, HIGH);

  //All switches pulled up to 5V internally. Turning a switch on, sends a GND signal to pin
  pinMode(Swicth_energySaver, INPUT_PULLUP);
  pinMode(Switch_fan, INPUT_PULLUP);
  pinMode(Switch_switchBoard2, INPUT_PULLUP);
  pinMode(Switch_socket, INPUT_PULLUP);

  //Code commented to allow for a diffenet approach below
  /*
    //Initially all switches assumed OFF without reading states. If mistake is made, it will automatically get rectified.
    //The actual states could also have been read, but eventually initail states will come from memory and this is temporary
    //depending on the switch state initially makes no sense.
    Sw_energySaver_State = false;
    Sw_fan_State = false;
    Sw_switchBoard2_State = false;
    Sw_socket_State = false;
  */

  //The switch states initially are read
  //This is a different approach to the code commented above
  //This approach allows for no appliances to be turned on until a state change occurs
  //The switch could be on or off, it won't matter

  Sw_energySaver_State = !(digitalRead(Swicth_energySaver));
  Sw_fan_State = !(digitalRead(Switch_fan));
  Sw_switchBoard2_State = !(digitalRead(Switch_switchBoard2));
  Sw_socket_State = !(digitalRead(Switch_socket));

  //Bluetooth States also assumed false initailly. There are no bluetooth commands initially and something has to be assumed.
  //Better a device be off than turned on for no reason.
  Bluetooth_energySaver_State = false;
  Bluetooth_fan_State = false;
  Bluetooth_switchBoard2_State = false;
  Bluetooth_socket_State = false;
}
 
void loop() {
  //the loop function exclusively only works for the Switch Board
  //Extra code is written that "interrupts" the regular flow, if a Bluetooth Command comes in
  delay(500); //delay to prevent debouncing
  readSwitchStates(); //Switches now read, extra code executed if change detected
  if (change == true) {
    updateStates();
  }
}
