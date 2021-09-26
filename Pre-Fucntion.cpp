#include <Adafruit_NeoPixel.h>
#define PIN 2	
#define NUMPIXELS 21 
// int Pin1 = A1, Pin2 = A2;
int Red_Value = 0, Blue_Value = 0, Green_Value = 0, delayval = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void testRange01(int i);
void testRange02(int i);
void testRange03(int i);
void testRange04(int i);
void testRange05(int i);
void testRange06(int i);
void testRange07(int i);
void testRange08(int i);
void testRange09(int i);


void setup() {
  Serial.begin(9600);
}

void loop() 
{
    // read the sensor:
    int sensorPin1 = analogRead(A1);
    int sensorPin2 = analogRead(A2);
    
    // map the sensor range to a range of four options:
    int mode = map(sensorPin1, 0, 1023, 0, 3);
    int range = map(sensorPin2, 0, 1023, 0, 3);
    switch(mode)
    {
        case 0:
        {
            Serial.println("Mode 1"); 
            switch(range)
            {
                case 0:
                {
                    Serial.println("Range 1.1");
                    testRange01(1);
                }
                break;
                case 1:
                {
                    Serial.println("Range 1.2");
                    testRange02(1);
                }
                break;
                case 2:
                {
                    Serial.println("Range 1.3");
                    testRange03(1);
                }
                break;
            }
        }
        break;
        case 1:
        {
            Serial.println("Mode 2"); 
            switch(range)
            {
                case 0:
                {
                    Serial.println("Range 2.1");
                    
                    testRange04(1);
                }
                break;
                case 1:
                {
                    Serial.println("Range 2.2");
                    testRange05(1);
                }
                break;
                case 2:
                {
                    Serial.println("Range 2.3");
                    testRange06(1);
                }
                break;
            }
        }
        break;
        case 2:
        {
            Serial.println("Mode 3"); 
            switch(range)
            {
                case 0:
                {
                    Serial.println("Range 3.1");
                    testRange07(1);
                }
                break;
                case 1:
                {
                    Serial.println("Range 3.2");
                    testRange08(1);
                }
                break;
                case 2:
                {
                    Serial.println("Range 3.3");
                    testRange09(1);
                }
                break;
            }
        }
        // Default:
        // {
        //     Serial.println("Default");
        // }
    }
}



void testRange01(int i)
{
    Serial.println("testInRange 1.1");
    Serial.println(i);

}

void testRange02(int i)
{
    Serial.println("testInRange 1.2");
}

void testRange03(int i)
{
    Serial.println("testInRange 1.3");
}

void testRange04(int i)
{
    Serial.println("testInRange 2.1");
}

void testRange05(int i)
{
    Serial.println("testInRange 2.2");
}

void testRange06(int i)
{
    Serial.println("testInRange 2.3");
}

void testRange07(int i)
{
    Serial.println("testInRange 3.1");
}

void testRange08(int i)
{
    Serial.println("testInRange 3.2");
}

void testRange09(int i)
{
    Serial.println("testInRange 3.3");
}
