#include "MPU6050.h"
#include "Wire.h"
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup()
{
  Wire.begin();
  Serial.begin(38400);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}
void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  ax = map(ax, -18000, 18000, 0, 180);
  ay = map(ay, -18000, 18000, 0, 180);
  az = map(az, -18000, 18000, 0, 180);
  gx = map(gx, -18000, 18000, 0, 180);
  gy = map(gy, -18000, 18000, 0, 180);
  gz = map(gz, -18000, 18000, 0, 180);


  //วัดค่าความเร่งเชิงเส้น
  //AZ ขนาดกับพื้น ค่าจะมากกว่า 150
  //AX ตั้งฉาก ค่าจะมากกว่า 150
  //AY เอียงขวา ค่าจะน้อยกว่า 50
  Serial.print("Axyz \t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");

  //วัดค่าความเร็วเชิงมุม
  Serial.print("Gxyz \t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);


  delay(100);
}
