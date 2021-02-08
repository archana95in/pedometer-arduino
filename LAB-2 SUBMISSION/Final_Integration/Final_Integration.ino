#include <Wire.h>
#include <SparkFunLSM9DS1.h>
LSM9DS1 imu;
int count, count_jump;
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
//Serial.println(" Y value, Z value"); 
//Serial.println(ay);
//Serial.println(az);

if( ay >=1.115 && ay <= 1.165)
 {    
    Serial.print(" It's a walk. Step Count = ");
    count++;
    Serial.println(count);
    delay(10);
  }

else if (ay >= 1.65 && ay <= 3 && az > 0)
  {   

    delay(100); 
    Serial.print("Its a jump. Jump Count = ");
    count_jump++; 
    Serial.println(count_jump-1);
       
  }
else 
{
}
delay(40);
}


















//#include <Wire.h>
//#include <SparkFunLSM9DS1.h>
//LSM9DS1 imu;
//int count = 0;
//int i = 0;
//int steps = 0;
//
//void setup()
//
//{
//Serial.begin(115200);
//Wire.begin();
//imu.begin();
//}
//
//void loop()
//{
//
//if ( imu.gyroAvailable() )
//imu.readGyro();
//if ( imu.accelAvailable() )
//imu.readAccel();
//if ( imu.magAvailable() )
//imu.readMag();
//
//float ax = imu.calcAccel(imu.ax);
//float ay = imu.calcAccel(imu.ay);
//float az = imu.calcAccel(imu.az);
//
////Serial.print(ax);
////Serial.print(", ");
////Serial.print(ay);
////Serial.print(", ");
////Serial.print((az));
////Serial.println();
//
//int i;
//
//
////float gx = imu.calcGyro(imu.gx);
////float gy = imu.calcGyro(imu.gy);
////float gz = imu.calcGyro(imu.gz);
////float mx = imu.calcMag(imu.mx);
////float my = imu.calcMag(imu.my);
////float mz = imu.calcMag(imu.mz);
////k = sqrt(sq(10*ax) + sq(10*ay) + sq(az));
//
////Serial.print(10*k);
////Serial.println();
////Serial.print(gx);
////Serial.print(", ");
////Serial.print(gy);
////Serial.print(", ");
////Serial.print((gz));
////Serial.println();
////Serial.print(mx);
////Serial.print(", ");
////Serial.print(my);
////Serial.print(", ");
////Serial.print((mz));
////Serial.println();
