/*
  IMU test:
  - just to check if connections and Arduino is working.
*/
#include <Arduino.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Wire.h>

MPU6050 sensor;

int16_t ax, ay, az;
int16_t gx, gy, gz;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);    //Iniciando puerto serial
  Wire.begin();           //Iniciando I2C  
  sensor.initialize();    //Iniciando el sensor

  if (sensor.testConnection()) 
    Serial.println("Sensor iniciado correctamente");
  else 
    Serial.println("Error al iniciar el sensor");
}

// the loop function runs over and over again forever
void loop() {
    // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);

  //Mostrar las lecturas separadas por un [tab]
  Serial.print("a[x y z] g[x y z]:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(100);
}