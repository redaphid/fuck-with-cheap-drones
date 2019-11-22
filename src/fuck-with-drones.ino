/*
 * Project fuck-with-drones
 * Description:
 * Author:
 * Date:
 */
int count = 0;
int oldValue = -1;
// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(D0, INPUT);
  Serial.begin(9600);
  Serial.println("starting up");
  Serial.flush();
  delay(1000);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  int newValue = digitalRead(D0);
  count++;
  if (newValue != oldValue) {
    Serial.println();
    Serial.println();
    if(count > 5) {
      Serial.println(count);
      Serial.println(newValue);
      oldValue = newValue;
    }

    count = 0;
  }
  delayMicroseconds(1);
}