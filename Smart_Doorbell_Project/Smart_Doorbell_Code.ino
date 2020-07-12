#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "<YourAuthTokenfromBlynk>";

//Wifi detail
char ssid[] = "<YourWifiSSID>";
char pass[] = "<YourWifiPassword>";

const int buttonpin = 16; //Pin D0
int buttonstate = 0;

void buttonpress(){
  Blynk.notify("Someone is at the door.");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonpin, INPUT);
  Blynk.begin(auth, ssid, pass);
  buttonstate = 0;
 
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
buttonstate = digitalRead(buttonpin);
if (buttonstate == 1){
  buttonpress();
}

}