// This #include statement was automatically added by the Particle IDE.
#include "DHT.h"

// Defining Pin
#define DHTPIN 2

// Defining Sensor type
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);

int red = D5;
int blue = D4;
int yellow = D3;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(yellow, OUTPUT);
    
	Serial.begin(9600);

    dht.begin();
}

void loop() {
    float t = dht.readTemperature();
    Particle.publish("temp", String(t), PRIVATE);
    checkTemp(t);
    delay(6000);      
}

int checkTemp(float t)
{
    if(t < 20)
    {
        digitalWrite(yellow, HIGH);
        delay(5000);
        digitalWrite(yellow, LOW);
    }
    else if(t > 30)
    {
        digitalWrite(red, HIGH);
        delay(5000);
        digitalWrite(red, LOW);
    }
    else
    {
        digitalWrite(blue, HIGH);
        delay(5000);
        digitalWrite(blue, LOW);
    }
}