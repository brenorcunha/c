#include <AFMotor.h>

#define SensorPinDir A5 // Right sensor
#define SensorPinEsq A0 // Left sensor
#define trig 2          // Ultrasonic TRIGGER PIN
#define echo 13         // Ultrasonic ECHO pin
unsigned long CM;       // Variable that keeps distance in CM

// Sensor readings:
int rightReading;
int leftReading;
boolean line = false;
float pulse;
// Right engine:
AF_DCMotor MDir(1);
// Left engine:
AF_DCMotor MEsq(4);

// Used velocities:
int constantVel = 150;
int rotationVel = 255;

void setup()
{
    Serial.begin(9600); // Initialize serial:
    Serial.println("5 segundos para iniciar");
    delay(5000); // Delay 5 secs.
    digitalWrite(trig, LOW);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    // Set engines to max velocity:
    MDir.setSpeed(255);
    MEsq.setSpeed(255);
}

void loop()
{
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    pulse = pulseIn(echo, HIGH, 7000);
    CM = pulse / 59;
    Serial.println(" ");
    Serial.print("Ultrasonic read: ");
    Serial.println(CM);

    // ENEMY SEARCHING CONDITION: If the robot reportas a 0 reading, it will go ahead:
    if (CM <= 0 && line == false)
    {
        moveForward();
        Serial.println("Searching for enemy...");
    }
    // Se inimigo estiver à frente, e robô não estiver perto da line,acontece o ataque:
    if (CM < 25 && line == false)
    {
        moveForward();
        Serial.println("Attack!");
    }
    else
    {
        moveRight();
        Serial.println("Searching for enemy...");
    }

    // Analog sensors reading:
    rightReading = analogRead(SensorPinDir);
    leftReading = analogRead(SensorPinEsq);
    Serial.print("Right: ");
    Serial.println(rightReading);
    Serial.print("Left: ");
    Serial.println(leftReading);

    // Line searching conditions:
    if (rightReading < 800 && leftReading < 800)
    {
        line = true;
        moveBackwards();
        Serial.println("Moving backwards");
    }
    else if (leftReading < 800)
    {
        line = true;
        moveRight();
        Serial.println("White line on the LEFT");
    }
    else if (rightReading < 800)
    {
        line = true;
        moveLeft();
        Serial.println("White line on the right");
    }
    else
    {
        line = false;
    }
}
// Engine control functions:
void moveForward()
{
    MDir.setSpeed(constantVel);
    MEsq.setSpeed(constantVel);
    MDir.run(FORWARD);
    MEsq.run(FORWARD);
    Serial.println("Moving forward.");
}

void moveRight()
{
    MEsq.setSpeed(rotationVel);
    MDir.setSpeed(0);
    MEsq.run(BACKWARD);
    // MDir.run(BACKWARD);
    Serial.println("Moving right.");
}

void moveLeft()
{
    MDir.setSpeed(rotationVel);
    MEsq.setSpeed(0);
    MDir.run(BACKWARD);
    // MEsq.run(FORWARD);
    Serial.println("Moving left.");
}

void moveBackwards()
{
    MDir.setSpeed(rotationVel);
    MEsq.setSpeed(rotationVel);
    MDir.run(BACKWARD);
    MEsq.run(BACKWARD);
    Serial.println("Moving backwards.");
}