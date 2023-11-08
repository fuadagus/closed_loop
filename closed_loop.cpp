#include <Servo.h>

Servo myServo;
const int inputFlexPin1 = A0;
const int inputFlexPin2 = A1;
const int servoPin = 9;

void setup() {
  myServo.attach(servoPin); // menghubungkan servo ke pin 9
  pinMode(inputFlexPin1, INPUT); // mengatur pin analog sebagai input untuk potensiometer pertama
  pinMode(inputFlexPin2, INPUT); // mengatur pin analog sebagai input untuk potensiometer kedua
  Serial.begin(115200);
}

int setPoint = 0;
int error=0;
int actualValue=0;
int setPointDegree = map(setPoint, 0, 1023, 0, 180);
int  errorDegree = map(error, 0, 1023, 0, 180);
int actualValueDegree = map(actualValue, 0, 1023, 0, 180);
void loop() {
  setPoint = analogRead(inputFlexPin1); 
  actualValue = map(analogRead(inputFlexPin2), 0, 1023, 0, 180); 
  error = setPoint - actualValue;
  setPointDegree = map(setPoint, 0, 1023, 0, 180);
  errorDegree = map(error, 0, 1023, 0, 180);
  Serial.print("SP: ");
  Serial.print(setPointDegree);
  Serial.print(" E: ");
  Serial.print(errorDegree);
  Serial.print(" AV: ");
  Serial.print(actualValueDegree);
  Serial.println("");
  setPoint = setPoint - error; 
  int servoPosition = map(setPoint, 0, 1023, 0, 180); 
  myServo.write(servoPosition); 
  delay(50); 
  }
