int ldrPin = A0; // connect the LDR to analog pin A0
int ledPin = 9; // connect the LED to digital pin 9

void setup() {
  pinMode(ledPin, OUTPUT); // set LED pin as output
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {
  int ldrValue = analogRead(ldrPin); // read LDR value
  Serial.println(ldrValue); // print LDR value for debugging

  if (ldrValue < 500) { // if LDR value is less than 500 (dark), turn on LED
    digitalWrite(ledPin, HIGH);
  } else { // otherwise, turn off LED
    digitalWrite(ledPin, LOW);
  }

  delay(100); // add a small delay to reduce flickering
}
