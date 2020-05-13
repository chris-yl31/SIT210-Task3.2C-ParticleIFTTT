// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"

int photoresistor = A0;
int analogValue;
double lightLevel = 0;
bool lighthitPublish = false;
bool lightnoPublish = false;
int minV = 10;
int maxV = 100;
bool IFTTT = false;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(photoresistor, INPUT);

}


void loop() {
 
analogValue = analogRead(photoresistor);
String light = String(analogValue);
Particle.publish("light", light, PRIVATE);

if (analogValue < minV)
{
    lightnoPublish = true;
    lighthitPublish = false;
    
} else if (analogValue > maxV)
{
    lighthitPublish = true;
    lightnoPublish = false;
}

if (lighthitPublish == true && IFTTT == true)
{
    Particle.publish("lightIFTTThit", "light", PRIVATE);
    IFTTT = false;
    
} else if (lightnoPublish == true && IFTTT == false)
{
    Particle.publish("lightIFTTTno", "no-light", PRIVATE);
    IFTTT = true;
}

delay(1000);
 
}