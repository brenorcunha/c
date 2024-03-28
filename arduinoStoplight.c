//Electronics lab project: Simulates a traffic control system using an Arduino Uno R3 and C language.
int carRedRight = 0;
int carYellowRight = 1;
int carGreenRight = 2;

int pedRedRight = 4;
int pedGreenRight = 3;

int carRedLeft = 10;
int carYellowLeft = 9;
int carYellowGreen = 8;

int pedRedLeft = 12;
int pedGreenLeft = 11;

int rightButton = 5;
int leftButton = 13;

unsigned long changeTime;
void setup()
{
  //Pin Configuration: Sets the pins of the Arduino Uno R3 as input or output.
  pinMode(carRedRight, OUTPUT);
  pinMode(carYellowRight, OUTPUT);
  pinMode(carGreenRight, OUTPUT);
  pinMode(pedRedRight, OUTPUT);
  pinMode(pedGreenRight, OUTPUT);
  pinMode(carRedLeft, OUTPUT);
  pinMode(carYellowLeft, OUTPUT);
  pinMode(carYellowGreen, OUTPUT);
  pinMode(pedRedLeft, OUTPUT);
  pinMode(pedGreenLeft, OUTPUT);
  
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
}

void loop()
{
  //Traffic Light Logic: Controls a traffic light system for pedestrians and cars based on the reading of the buttons.
  int rightState = digitalRead(rightButton);
  int leftState = digitalRead(leftButton);
  
  //Traffic Light Cycle: Establishes a traffic light change cycle with defined delays.
  if (rightState == HIGH && pedRedRight==HIGH && (millis()-changeTime)>5000)
  {
    delay(5000);
    closeCarRight();
    openCarLeft();
  	openPedRight();
  	closePedLeft();
    changeTime = millis();
  	
  } else if (leftState == HIGH && pedRedLeft==HIGH && (millis()-changeTime)>5000)
  {
    delay(5000);
    closeCarLeft();
  	openCarRight();
  	openPedLeft();
  	closePedRight();
    changeTime = millis();
  	
  }
  openCarLeft();
  closeCarRight();
  closePedLeft();
  openPedRight();
  delay(30000);
  
  closeCarLeft();
  openCarRight();
  openPedLeft();
  closePedRight();
  delay(30000);
  
  changeTime = millis();
}

void openCarLeft(){
  digitalWrite(carRedLeft, LOW);
  digitalWrite(carYellowGreen, HIGH);
}

void openPedLeft(){
  digitalWrite(pedRedLeft, LOW);
  digitalWrite(pedGreenLeft, HIGH);
}

void closeCarLeft(){
  digitalWrite(carYellowGreen, LOW);
  digitalWrite(carYellowLeft, HIGH);
  delay(1000);
  digitalWrite(carYellowLeft, LOW);
  digitalWrite(carRedLeft, HIGH);
}

void closePedLeft(){  
  digitalWrite(pedGreenLeft, LOW);
  digitalWrite(pedRedLeft, HIGH);
}

void openCarRight(){
  digitalWrite(carRedRight, LOW);
  digitalWrite(carGreenRight, HIGH);
}

void openPedRight(){
  digitalWrite(pedRedRight, LOW);
  digitalWrite(pedGreenRight, HIGH);
}

void closeCarRight(){
  digitalWrite(carGreenRight, LOW);
  digitalWrite(carYellowRight, HIGH);
  delay(1000);
  digitalWrite(carYellowRight, LOW);
  digitalWrite(carRedRight, HIGH);
}

void closePedRight(){
  digitalWrite(pedGreenRight, LOW);
  digitalWrite(pedRedRight, HIGH);
}