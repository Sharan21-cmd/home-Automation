#include <DHT.h>
#include <ESP32Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34
#define PIR_PIN 27
#define BUZZER 26
#define LED 25
#define SERVO_PIN 18
DHT dht(DHTPIN, DHTTYPE);
Servo servo;
bool tempAlert = false;
bool lightOn = false;
bool motionDetected = false;

void setup() 
{
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0);

  dht.begin();
}

void loop() 
{

  float temp = dht.readTemperature();
  int ldrValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  if (!isnan(temp) && temp > 30) 
  {
    tempAlert = true;
  } else {
    tempAlert = false;
  }

  if (ldrValue < 1000) 
  {
    lightOn = true;
  } else {
    lightOn = false;
  }

  
  if (motion == HIGH)
   {
    motionDetected = true;
  } else {
    motionDetected = false;
  }


  if (lightOn || tempAlert) 
  {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  if (motionDetected || tempAlert)
  {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }
  if (motionDetected) 
  {
    Serial.println(" Motion Detected → Door Opening");
    servo.write(90);
    delay(2000);
    servo.write(0);
  }

  Serial.println("------ STATUS ------");

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Temp Alert: ");
  Serial.println(tempAlert ? "ON" : "OFF");

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Light: ");
  Serial.println(lightOn ? "ON (Dark)" : "OFF (Bright)");

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Motion Detected: ");
  Serial.println(motionDetected ? "YES" : "NO");

  Serial.print("LED: ");
  Serial.println((lightOn || tempAlert) ? "ON" : "OFF");

  Serial.print("Buzzer: ");
  Serial.println((motionDetected || tempAlert) ? "ON" : "OFF");

  Serial.println("--------------------\n");

  delay(500);
}
