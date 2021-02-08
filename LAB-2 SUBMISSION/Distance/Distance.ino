#include <Wire.h>
#include <SparkFunLSM9DS1.h>
LSM9DS1 imu;
int count; 
int count_jump = 1;
unsigned long start,finish;
float velocity, elapsed_milli;
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
{
imu.readAccel();
start = millis();
}

if ( imu.magAvailable() )
imu.readMag();

float ax = imu.calcAccel(imu.ax);
float ay = imu.calcAccel(imu.ay);
float az = imu.calcAccel(imu.az);

if( ay >=1.115 && ay <= 1.165)
  {
    Serial.print(" It's a walk. Step Count = ");
    count++;
    Serial.println(count);
    delay(10);
  }

else if (ay >= 1.65 && ay <= 3 && az > 0)
  {
    finish = millis();
    delay(100); 
    Serial.print("Its a jump. Jump Count = ");
    count_jump++; 
    Serial.println(count_jump-1);
    elapsed_milli=(finish-start);
    Serial.print("In the air for ");
    Serial.print(elapsed_milli);      
    Serial.println("ms");
    velocity = (ay * elapsed_milli);
    Serial.print("Velocity");
    Serial.print(velocity);      
    Serial.println("m/s");
    
  }
delay(40);
}
