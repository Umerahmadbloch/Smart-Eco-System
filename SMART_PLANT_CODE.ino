#define BLYNK_TEMPLATE_ID "TMPL6IZZQa_vU"
#define BLYNK_TEMPLATE_NAME "JACKET"
#define BLYNK_AUTH_TOKEN "xt-4sj_LHIcSUf3SviLn86kQ4t9Z_ce3"
#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial

#include "HX711.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT22
char ssid[] = "MR";
char pass[] = "zuMA2017";
#define calibration_factor 190.0
#define LOADCELL_DOUT_PIN D5
#define LOADCELL_SCK_PIN D6
// #define GAS D1
#define Light D2
#define pump D3
#define fan D0
#define LED D7

String Lightstr = "";
String Pumpstr = "";
String Fan_str = "";

HX711 scale;

float FAN_THRUSHOLD = 25;
float SOIL_THRUSHOLD = 670;

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h, t;
  int Light_value, soil_val;
  h = dht.readHumidity();
  t = dht.readTemperature();
  Light_value = digitalRead(Light);
  soil_val = analogRead(A0);
  float Weight = scale.get_units();



  if (Light_value == LOW) {
    digitalWrite(LED, LOW);
    Lightstr = "LIGHT OFF!";
  } else {
    digitalWrite(LED, HIGH);
    Lightstr = "LIGHT ON!";
  }

  if (soil_val > SOIL_THRUSHOLD) {
    digitalWrite(pump, LOW);
    Pumpstr = "PUMP ON!";
  } else {
    digitalWrite(pump, HIGH);
    Pumpstr = "PUMP OFF!";
  }

  if (!isnan(h) && !isnan(t)) {

    if(t > FAN_THRUSHOLD){
      digitalWrite(fan, LOW);
      Fan_str = "FAN ON!";
    }
    else{
      digitalWrite(fan, HIGH);
      Fan_str = "FAN OFF!";
    }
    
  }

  Serial.println(Light_value);

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V8, Pumpstr);
  Blynk.virtualWrite(V7, Lightstr);
  Blynk.virtualWrite(V1, soil_val);
  Blynk.virtualWrite(V4, Weight);
  Blynk.virtualWrite(V9, Fan_str);
}

void setup() {
  Serial.begin(115200);
  pinMode(Light, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(DHTPIN,OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  timer.setInterval(200L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}