#include <CurieIMU.h>
#include <CurieTime.h>
int readVal1, readVal2, readVal3, choice;
int count = 0;
long timeOld = 0, timeNew = 0;

void setup() {
  //Setup for Analog input pins and IMU
  pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A2, INPUT);
  CurieIMU.begin(); CurieIMU.setGyroRange(250);
  CurieIMU.setAccelerometerRange(2);
  Serial.begin(115200);  //Setup serial at 115200 baud
  while (!Serial);  //Wait until Serial Monitor is opened
  Serial.println("Type 1 to sample from the analog input, type 2, Gyro, 3, Accelerometer");
  while (!Serial.available());  //Wait until a character is received
  choice = Serial.read() - (int)'0';  //Read the input as ASCII, convert to int and store in variable
  timeNew = micros();  //Get an initial time
}

void loop() {
  timeOld = timeNew;
  if (choice == 1) {
    //Get the system time before the reading assignment
    readVal1 = analogRead(A0); readVal2 = analogRead(A1); readVal3 = analogRead(A2);
    count++;
  }
  else if (choice == 2) {
    //Get the system time before the reading assignment
    CurieIMU.readGyro(readVal1, readVal2, readVal3);
    count++;
  }
  else if (choice == 3) {
    //Get the system time before the reading assignment
    CurieIMU.readAccelerometer(readVal1, readVal2, readVal3);
    count++;
  }
  Serial.print(count); Serial.print("\t"); Serial.print(readVal1);
  Serial.print("\t"); Serial.print(readVal2); Serial.print("\t");
  Serial.print(readVal3); Serial.print("\t");
  //Add extra delay to make the loop time 10000 microseconds
  delayMicroseconds(10000 - (micros() - timeOld) - 1); //-1 to cancel the offset caused by printing statements
  Serial.println(micros() - timeOld);
  //Get the time at the end of the loop
  timeNew = micros();
}
