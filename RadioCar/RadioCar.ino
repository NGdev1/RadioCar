// Необходимо установить библиотеку для радиомодуля nRF24
#include <Servo.h>
#include <SPI.h>
#include "RF24.h"
Servo servo1;

RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int msg[1];
int data;
int pos;
int fspeed;         // forward speed
const int in1 = 6; // direction pin 1

void setup()
{
    Serial.begin(9600);
    Serial.print("Start!");
    pinMode(in1, OUTPUT); // connection to L298n
    servo1.attach(4);
    delay(50);
    radio.begin();
    radio.openReadingPipe(1, pipe);
    radio.startListening();
}

void loop()
{
     if (radio.available())radio.read(msg, 1);
      Serial.println(msg[0]);
     if(msg[0] > 120) {
      forward(255);
      msg[0] -= 120;
     } else {
      stop();
     }
     
     if (msg[0] <110 && msg[0] >-1)
       data = msg[0], pos = map(data, 0, 100, 45, 115),servo1.write(pos);
}

void stop()
{
    analogWrite(in1, 0);
}

void forward(int fspeed)
{
    analogWrite(in1, fspeed);
}
