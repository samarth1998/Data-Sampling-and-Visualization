#include <CurieIMU.h>
#include <CurieTime.h>

long time1, time2;  //Declear local variable to store time
void setup() {
  //Setup the serial and setup analog pin and IMUs
  Serial.begin(115200);
  //Initialize Sensors
  pinMode(A0, INPUT);
  CurieIMU.begin();
  CurieIMU.setGyroRange(250);
  CurieIMU.setAccelerometerRange(2);
}

void loop() {
  float ax, ay, az;  //Declear variables to store data read by Accelerometer
  int gx, gy, gz;    //Declear variables to store data read by gyroscope
  Serial.println("Microseconds for analogRead");
  time1 = micros();  //Store the time before reading
  analogRead(A0);  //Read raw data once
  time2 = micros();  //Store the time after reading
  Serial.println(time2 - time1); //Get the time difference and print
  delay(100);
  Serial.println("Microseconds for Gyro read");
  time1 = micros();  //Store the time before reading
  CurieIMU.readGyro(gx, gy, gz);  //Read raw data once
  time2 = micros();  //Store the time after reading
  Serial.println(time2 - time1);  //Get the time difference and print
  delay(100);
  Serial.println("Microseconds for Accel read");
  time1 = micros();  //Store the time before reading
  CurieIMU.readAccelerometerScaled(ax, ay, az);  //Read raw data once
  time2 = micros();  //Store the time after reading
  Serial.println(time2 - time1);  //Get the time difference and print
  delay(100);
}
