int speed = 200; 

void setup() {
  Serial.begin(9600);
  DDRD = 0b11110000;
  Serial.println("Type 'f' for Faster, 's' for Slower.");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'f' || cmd == 'F') {
      speed -= 30; 
      if (speed < 50) speed = 50; 
      Serial.print("New Speed: ");
      Serial.print(speed);
      Serial.println(" ms");
    } 
    else if (cmd == 's' || cmd == 'S') {
      speed += 30; 
      if (speed > 1000) speed = 1000; 
      Serial.print("New Speed: ");
      Serial.print(speed);
      Serial.println(" ms");
    }
  }

  for (int pin = 4; pin <= 7; pin++) {
    PORTD = (1 << pin); 
    delay(speed);
    checkSerialDuringDelay();
  }

  for (int pin = 6; pin >= 5; pin--) {
    PORTD = (1 << pin);
    delay(speed);
    checkSerialDuringDelay();
  }
}

void checkSerialDuringDelay() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'f' || cmd == 'F') {
      speed -= 30;
      if (speed < 50) speed = 50;
      Serial.print("New Speed: ");
      Serial.print(speed);
      Serial.println(" ms");
    } 
    else if (cmd == 's' || cmd == 'S') {
      speed += 30;
      if (speed > 1000) speed = 1000;
      Serial.print("New Speed: ");
      Serial.print(speed);
      Serial.println(" ms");
    }
  }
}