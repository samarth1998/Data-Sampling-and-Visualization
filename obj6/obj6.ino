#include "CurieTimerOne.h"
#include <BMI160.h>
#include <CurieIMU.h>
#include <CurieTime.h>
#define FREQUENCY 100  //Setup the target sampling frequency (Hz)
long timeOld = 0, timeNew = 0, count = 0;
int readVal1, readVal2, readVal3, choice;
void analogSampleIsr()   // callback function when interrupt is asserted
{
  timeNew = micros();
  //Read sensor data
  readVal1 = analogRead(A0); readVal2 = analogRead(A1); readVal3 = analogRead(A2);
  count++;
  Serial.print(count); Serial.print("\t"); Serial.print(readVal1);
  Serial.print("\t"); Serial.print(readVal2); Serial.print("\t");
  Serial.print(readVal3); Serial.print("\t");
  Serial.println(timeNew - timeOld);
  timeOld = timeNew;

}

void gyroSampleIsr()   // callback function when interrupt is asserted
{
  timeNew = micros();
  //Read sensor data
  CurieIMU.readGyro(readVal1, readVal2, readVal3);
  count++;
  Serial.print(count); Serial.print("\t"); Serial.print(readVal1);
  Serial.print("\t"); Serial.print(readVal2); Serial.print("\t");
  Serial.print(readVal3); Serial.print("\t");
  Serial.println(timeNew - timeOld);
  timeOld = timeNew;
}

void accSampleIsr()   // callback function when interrupt is asserted
{
  timeNew = micros();
  //Read sensor data
  CurieIMU.readAccelerometer(readVal1, readVal2, readVal3);
  count++;
  Serial.print(count); Serial.print("\t"); Serial.print(readVal1);
  Serial.print("\t"); Serial.print(readVal2); Serial.print("\t");
  Serial.print(readVal3); Serial.print("\t");
  Serial.println(timeNew - timeOld);
  timeOld = timeNew;
}
void setup() {
  //  //Setup for Analog input pins and IMU
  //  pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A2, INPUT);
  //  CurieIMU.begin(); CurieIMU.setGyroRange(250);
  //  CurieIMU.setAccelerometerRange(2);
    Serial.begin(115200);  //Setup serial at 115200 baud
  //  while (!Serial);  //Wait until Serial Monitor is opened
  //  Serial.println("Type 1 to sample from the analog input, type 2, Gyro, 3, Accelerometer");
  //  while (!Serial.available());  //Wait until a character is received
  //  choice = Serial.read() - (int)'0';  //Read the input as ASCII, convert to int and store in variable
  //  int period = 1000000 / FREQUENCY;  //Setup the sampling period
  //  timeNew = micros();  //Get an initial time
  //  if (choice == 1)
  //    CurieTimerOne.start(period, &analogSampleIsr);// set timer and callback to Analog Sampling
  //  else if (choice == 2)
  //    CurieTimerOne.start(period, &gyroSampleIsr);  // set timer and callback to Gyro Sampling
  //  else if (choice == 3)
  //    CurieTimerOne.start(period, &accSampleIsr);   // set timer and callback to Acc Sampling
  //  timeOld = micros();
}

void loop() {
  count++;
  Serial.write(count);
}
