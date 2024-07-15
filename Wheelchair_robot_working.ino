//MOTOR1 PINS
int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;

int command; // Int to store app command state.

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);  // Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); // Initialize with motors stopped.
    switch (command) {
      case 'F':
      Serial.println("Forward command received"); // Send message back to app
       forward();
        break;
      case 'B':
        Serial.println("Backward command received"); // Send message back to app
        back();
        break;
    }
  }
}

void forward() {
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);

  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  delay(1000);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);

  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  delay(1000);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);

  back();
}

void back() {
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);

  delay(1000);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);

  digitalWrite(in3, HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);

  delay(1000);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(ena, 100);
  analogWrite(enb, 100);

  delay(1000);
}

void Stop() {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(300);
}
