// Define the pins for the L298 motor driver
int enA = 10; // PWM signal for controlling motor speed
int in1 = 9;  // direction control for motor A
int in2 = 8;  // direction control for motor A
int enB = 5;  // PWM signal for controlling motor speed
int in3 = 7;  // direction control for motor B
int in4 = 6;  // direction control for motor B

// Define the pins for the line sensor
int leftSensor = 2;
int rightSensor = 3;

// Define the threshold for detecting the black line
int threshold = 500;

void setup() {
  // Set the motor driver pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set the line sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  // Read the values of the line sensors
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Determine the direction to turn based on the line sensor readings
  if (leftValue == LOW && rightValue == LOW) { // both sensors on the line
    // Go straight
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (leftValue == HIGH) { // left sensor on the line
    // Turn left
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (rightValue == HIGH) { // right sensor on the line
    // Turn right
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else { // both sensors off the line
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  // Set the motor speed
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}
