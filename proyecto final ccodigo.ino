#include <Adafruit_NeoPixel.h>
 
#define LED_PIN 6        
#define NUM_PIXELS 61    
#define SENSOR_PIN_1 A0  
#define SENSOR_PIN_2 A1  
#define SENSOR_PIN_3 A2  
#define SENSOR_PIN_4 A3  
#define SENSOR_PIN_5 A5  
#define SENSOR_PIN_6 A6  
 
Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
 
void configurarColorAnillo(int inicio, int fin, int rojo, int verde, int azul) {
  for (int i = inicio; i <= fin; i++) {
    strip.setPixelColor(i, strip.Color(rojo, verde, azul));
  }
}
 
void setup() {
  Serial.begin(9600); 	
  strip.begin();      	
  strip.show();       	
}
 
void loop() {
  int sensorValue1 = analogRead(SENSOR_PIN_1);
  int sensorValue2 = analogRead(SENSOR_PIN_2);
  int sensorValue3 = analogRead(SENSOR_PIN_3);
  int sensorValue4 = analogRead(SENSOR_PIN_4);
  int sensorValue5 = analogRead(SENSOR_PIN_5);
  int sensorValue6 = analogRead(SENSOR_PIN_6);
 
 
  int dbValue1 = map(sensorValue1, 130, 500, 0, 100);
  int dbValue2 = map(sensorValue2, 130, 500, 0, 100);
  int dbValue3 = map(sensorValue3, 130, 500, 0, 100);
  int dbValue4 = map(sensorValue4, 130, 500, 0, 100);
  int dbValue5 = map(sensorValue5, 130, 500, 0, 100);
  int dbValue6 = map(sensorValue6, 130, 500, 0, 100);
  int FinalValue = dbValue1 + dbValue2 + dbValue3 + dbValue4 + dbValue5 + dbValue6;
 
  Serial.print("Sensor 0: ");
  Serial.print("\tSensor 1: ");
  Serial.print("\tSensor 2: ");
  Serial.print("\tSensor 3: ");
  Serial.print("\tSensor 4: ");
  Serial.print("\tSensor 5: ");
  Serial.println("\tValor Final: ");
  Serial.print(dbValue1);
  Serial.print("\t\t");
  Serial.print(dbValue2);
   Serial.print("\t\t");
  Serial.print(dbValue3);
   Serial.print("\t\t");
  Serial.print(dbValue4);
   Serial.print("\t\t");
  Serial.print(dbValue5);
   Serial.print("\t\t");
  Serial.print(dbValue6);
   Serial.print("\t\t");
  Serial.print(FinalValue);
  Serial.println("");
 
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
   if (FinalValue > 0) {
    configurarColorAnillo(0, 4 + 0 / 10, 0, 255, 0); // final verde, inicia el amarillo
  }
   if (FinalValue > 50) {
    configurarColorAnillo(4, 8 + 0 / 10, 25, 255, 0);
  }
  if (FinalValue > 100) {
    configurarColorAnillo(8, 12 + 0 / 10, 50, 255, 0);
  }
  if (FinalValue > 150) {
    configurarColorAnillo(12, 16 + 0 / 10, 91, 255, 0);
  }
  if (FinalValue > 200) {
    configurarColorAnillo(16, 20 + 0 / 10, 132, 255, 0);
  }
  if (FinalValue > 250) {
    configurarColorAnillo(20, 24 + 0 / 10, 255, 255, 0);
  }
  if (FinalValue > 300) {
    configurarColorAnillo(24, 28  + 0 / 10, 255, 255, 0);
  }
  if (FinalValue > 350) {
    configurarColorAnillo(28, 32 + 0 / 10, 255, 255, 0); // final amarillo, inicia el rojo
  }
  if (FinalValue > 400) {
    configurarColorAnillo(32, 36 + 0 / 10, 255, 80, 0);
  }
  if (FinalValue > 450) {
    configurarColorAnillo(36, 40 + 0 / 10, 255, 60, 0);
  }
  if (FinalValue > 500) {
    configurarColorAnillo(40, 44 + 0 / 10, 255, 40, 0);
  }
  if (FinalValue > 550) {
    configurarColorAnillo(44, 48 + 0 / 10, 255, 30, 0);
  }
  if (FinalValue > 600) {
    configurarColorAnillo(48, 52  + 0 / 10, 255, 20, 0);
  }
  if (FinalValue > 650) {
    configurarColorAnillo(52, 56 + 0 / 10, 255, 10, 0);
  }
  if (FinalValue > 700) {
    configurarColorAnillo(56, 60 + 0 / 10, 255, 0, 0); // final rojo
  }
 
 
  strip.show();
  delay(5);
}
