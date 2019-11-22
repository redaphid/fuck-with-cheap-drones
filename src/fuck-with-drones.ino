/*
 * Project fuck-with-drones
 * Description:
 * Author:
 * Date:
 */
int count = 0;
int oldValue = -1;
#define LED D7
#define PROBE A0
#define BUTTON D6
// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(PROBE, INPUT_PULLDOWN);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLDOWN);
  Serial.begin(9600);
  Serial.println("starting up v10");
  Serial.flush();
  digitalWrite(LED, HIGH);
  delay(1000);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if(digitalRead(BUTTON)) {
    delay(500);
    Serial.println("waiting.");
    return;
  }
  int newValue = analogRead(PROBE);
  count++;
  if (abs(newValue - oldValue) > 700) {
    Serial.println();
    int bit = 0;
    if (newValue > oldValue) bit = 1;
    int times = (micros() - count) / 5000; 
    Serial.print(bit);
    Serial.print("x");
    Serial.println(times);

    oldValue = newValue;
    digitalWrite(LED, newValue);
    count = micros();
  }
}