#include <Wire.h>
#include <SparkFunLSM9DS1.h>
LSM9DS1 imu;
int count = 0;
int i = 0;
int steps = 0;

void setup()

{
Serial.begin(115200);
Wire.begin();
imu.begin();
}

void loop()
{

if ( imu.gyroAvailable() )
imu.readGyro();
if ( imu.accelAvailable() )
imu.readAccel();
if ( imu.magAvailable() )
imu.readMag();

float ax = imu.calcAccel(imu.ax);
float ay = imu.calcAccel(imu.ay);
float az = imu.calcAccel(imu.az);

int i;
if (ay > 1.115)
  {
    count++;
    delay(200);
  }
steps = count;
Serial.println("Number of Steps = ");
Serial.println(count);
delay(50);
}
