int relayPin1 = 4;  //This is the Arduino Pin that will control Relay #1
int relayPin2 = 6;  //This is the Arduino Pin that will control Relay #2

 
void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(relayPin1, HIGH);
  delay(1000);
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, HIGH);
  delay(1000);
  digitalWrite(relayPin2, LOW);
  delay(1000);
}
