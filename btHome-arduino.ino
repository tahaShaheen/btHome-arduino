/*
   Made by Taha Shaheen
   Start Date: 22nd Aug 2017
   Restart Date: 21st Oct 2017
   End Date: 28th Aug 2017

   This version supports updating based on latest input
   be it from BT or Switch Board
   It is being designed to function with a rudimentary bluetooth app.

   There is no memory. Initial startup positions are based on Switch Board Positions.

*/

#define RELAY_socket 7   //Socket
#define RELAY_switchBoard2 6   //SwitchBoard2
#define RELAY_fan 5   //Fan
#define RELAY_energySaver 4   //Energy Saver

#define Swicth_energySaver A0    //Energy Saver
#define Switch_fan A1    //Fan
#define Switch_switchBoard2 A2    //SwitchBoard2
#define Switch_socket A3    //Socket

String inputString = "";
boolean stringComplete = false;
boolean Sw_energySaver_State, Sw_fan_State, Sw_switchBoard2_State, Sw_socket_State, Sw_energySaver_StatePrevious, Sw_fan_StatePrevious, Sw_switchBoard2_StatePrevious, Sw_socket_StatePrevious;
boolean Bluetooth_socket_State, Bluetooth_switchBoard2_State, Bluetooth_fan_State, Bluetooth_energySaver_State;
boolean change;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready...");

  inputString.reserve(200);   //Reserved for Serial Event input characters

  //All relay pins made output
  pinMode(RELAY_socket, OUTPUT);
  pinMode(RELAY_switchBoard2, OUTPUT);
  pinMode(RELAY_fan, OUTPUT);
  pinMode(RELAY_energySaver, OUTPUT);

  //All switches pulled up to 5V internally. Turning a switch on, sends a GND signal to pin
  pinMode(Swicth_energySaver, INPUT_PULLUP);
  pinMode(Switch_fan, INPUT_PULLUP);
  pinMode(Switch_switchBoard2, INPUT_PULLUP);
  pinMode(Switch_socket, INPUT_PULLUP);

  //Initially all switches assumed OFF without reading states. If mistake is made, it will automatically get rectified.
  //The actual states could also have been read, but eventually initail states will come from memory and this is temporary
  //depending on the switch state initially makes no sense.
  Sw_energySaver_State = false;
  Sw_fan_State = false;
  Sw_switchBoard2_State = false;
  Sw_socket_State = false;

  //Bluetooth States also assumed false initailly. There are no bluetooth commands initially and something has to be assumed.
  //Better a device be off than turned on for no reason.
  Bluetooth_socket_State = false;
  Bluetooth_switchBoard2_State = false;
  Bluetooth_fan_State = false;
  Bluetooth_energySaver_State = false;

  //Initailly all Relays turned off. Relays are ACTIVE LOW. (The opto-coupler is ACTIVE LOW)
  digitalWrite(RELAY_socket, HIGH);
  digitalWrite(RELAY_switchBoard2, HIGH);
  digitalWrite(RELAY_fan, HIGH);
  digitalWrite(RELAY_energySaver, HIGH);
}

void loop() {
  //the loop function exclusively only works for the Switch Board
  //Extra code is written that "interrupts" the regular flow, if a Bluetooth Command comes in
  readSwitcheStates(); //Switches now read, extra code executed if change detected
}
