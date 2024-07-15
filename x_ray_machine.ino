#include <HCSR04.h>

// Define the pins for the LEDs
#define GREEN_LED 3
#define YELLOW_LED 4
#define RED_LED 5

// Define the pins for the ultrasonic sensor
#define TRIGGER_PIN 7
#define ECHO_PIN 6

// Create an instance of the HCSR04 class
HCSR04 hc(TRIGGER_PIN, ECHO_PIN);

void setup() {
  // Initialize the serial communication for debugging purposes
  Serial.begin(9600);

  // Set the LED pins as OUTPUT
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Measure the distance in centimeters
  double distance_cm = hc.dist();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Control LEDs based on the distance
  if (distance_cm < 15) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  } else if (distance_cm >= 15 && distance_cm < 25) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }

  // Add a small delay to avoid flooding the serial output
  delay(500);
}
