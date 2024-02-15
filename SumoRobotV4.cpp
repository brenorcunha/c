#include <AFMotor.h>

#define TSU xxx // Ultrasonic Trigger Pin
#define ESU 13 // Ultrasonic Echo Pin
#define S1 A5  // Right sensor input
#define S2 A0  // Left sensor input
#define S3 A1  // Rear sensor input

// Specifying speeds
byte halfSpeed = 115;
byte maxSpeed = 150;
int duration = 2000;
int vs1, vs2, vs3;

// Define motor1 connected to channel 1
AF_DCMotor motor1(1);
// Define motor2 connected to channel 2
AF_DCMotor motor2(4);

void setup() {
    pinMode(TSU, OUTPUT); // Output for ultrasonic trigger
    pinMode(ESU, INPUT);  // Input for ultrasonic echo
    pinMode(S1, INPUT);   // Sensor 1 in the arena
    pinMode(S2, INPUT);   // Sensor 2 in the arena
    pinMode(S3, INPUT);   // Sensor 3 in the arena

    digitalWrite(TSU, LOW); // Trigger pin starts low
    randomSeed(analogRead(7));

    // Initialize serial communication
    Serial.begin(9600);
    Serial.println("Serial initialized");
    Serial.println("5 seconds to start");
    delay(5000); // Wait for 5 seconds before starting
    Serial.println("Start");

    // Set maximum speed for motors 1 and 2
    motor1.setSpeed(150);
    motor2.setSpeed(150);
}

// This function generates the ultrasonic pulse.
void pulse() {
    digitalWrite(TSU, HIGH); // Trigger output goes high
    delayMicroseconds(10);   // Wait for 10 microseconds
    digitalWrite(TSU, LOW);  // Trigger output goes low
}

// This function triggers and returns the distance.
int measureDistance() {
    int pulse, dist_cm;
    pulse();
    pulse = pulseIn(ESU, HIGH, 4706); // Maximum wait time for ultrasound (5000 or 4706 corresponds to 80 cm).
    dist_cm = pulse; // Removed division for CM calculation.
    Serial.println("Ultrasonic reading: ");
    Serial.println(dist_cm);
    Serial.println("\n");
    return dist_cm;
}

void writeAnalogVelocities() {
    vs1 = analogRead(S1);
    vs2 = analogRead(S2);
    vs3 = analogRead(S3);
    Serial.println("Sensor readings: ");
    Serial.println(vs1);
    Serial.println(vs2);
    Serial.println(vs3);
}


// Start the left motor forward and the right motor backward
void left(byte speed) {
    motor1.setSpeed(speed);
    motor1.run(FORWARD);
    motor2.setSpeed(0);
}

// Start the right motor forward and the left motor backward
void right(byte speed) {
    motor1.setSpeed(0);
    motor2.setSpeed(speed);
    motor2.run(FORWARD);
}

// Turn off both motors
void stop() {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
}

// The `forward()` function activates both motors to move forward
void forward(byte speed) {
    motor1.setSpeed(speed);
    motor1.run(FORWARD);
    motor2.setSpeed(speed);
    motor2.run(FORWARD);
}

// The `reverse()` function activates both motors to move backward
void reverse(byte speed) {
    motor1.setSpeed(speed);
    motor1.run(BACKWARD);
    motor2.setSpeed(speed);
    motor2.run(BACKWARD);
}

// This technique uses the noise from an unplugged pin to create a random direction
void randomDirection(byte speed, int duration) {
    long randNumber = random(0, 30);
    if (randNumber <= 10) {
        left(speed);
    } else if (randNumber > 10 && randNumber <= 20) {
        right(speed);
    } else {
        forward(speed);
    }
}

void loop() {
    randomDirection(halfSpeed, duration);
    writeAnalogVelocities();
    measureDistance();
    delayMicroseconds(5000);
    if (vs1 <= 800) {
        stop();
        right(halfSpeed);
    }
    if (vs2 <= 800) {
        stop();
        left(halfSpeed);
    }
    if (vs3 <= 800) {
        Serial.println("White line detected behind");
        stop();
        forward(halfSpeed);
    }
    if (measureDistance() <= 4706) {
        forward(maxSpeed);
    } else {
        Serial.println("No one nearby");
        randomDirection(halfSpeed, duration);
    }
}

