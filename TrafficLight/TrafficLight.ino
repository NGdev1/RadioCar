#include "MDButton.h"

int buttonStartPin = 2;
MDButton buttonStart(buttonStartPin);

int greenLightPin = 3;
int yellowLightPin = 4;
int redLightPin = 5;

void buttonStartPressed()
{
    red();
    delay(2000);
    yellow();
    delay(2000);
    green();
}

void green()
{
    digitalWrite(greenLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(redLightPin, LOW);
}

void yellow()
{
    digitalWrite(greenLightPin, LOW);
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(redLightPin, LOW);
}

void red()
{
    digitalWrite(greenLightPin, LOW);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(redLightPin, HIGH);
}

void setup()
{
    pinMode(greenLightPin, OUTPUT);
    pinMode(yellowLightPin, OUTPUT);
    pinMode(redLightPin, OUTPUT);
}

void loop()
{
    if (buttonStart.isPressed())
    {
        buttonStartPressed();
    }
}
