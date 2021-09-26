#include <Adafruit_NeoPixel.h>
#define PIN 2	
#define NUMPIXELS 48 
// int Pin1 = A1, Pin2 = A2;
int Red_Value = 0, Blue_Value = 0, Green_Value = 0, delayval = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void redBasic(int i);
void greenBasic(int i);
void blueBasic(int i);
void Red_ForBack_Ward(int i);
void Green_ForBack_Ward(int i);
void Blue_ForBack_Ward(int i);
void RainBow(int i);
void FadeInOut(int i);
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
    int mode = map(sensorPin1, 0, 1023, 0, 2);
    int range = map(sensorPin2, 0, 1023, 0, 2);
    switch(mode)
    {
        case 0:
        {   
            Serial.println("Mode 1"); 
            switch(range)
            {
                case 0:
                {
                    // Serial.println("Range 1.1");
                    redBasic(1);
                }
                break;
                case 1:
                {
                    // Serial.println("Range 1.2");
                    greenBasic(1);
                }
                break;
                case 2:
                {
                    // Serial.println("Range 1.3");
                    blueBasic(1);
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
                    // Serial.println("Range 2.1");                  
                    Red_ForBack_Ward(1);
                }
                break;
                case 1:
                {
                    // Serial.println("Range 2.2");
                    Green_ForBack_Ward(1);
                }
                break;
                case 2:
                {
                    // Serial.println("Range 2.3");
                    Blue_ForBack_Ward(1);
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
                    // Serial.println("Range 3.1");
                    RainBow(1);
                }
                break;
                case 1:
                {
                    // Serial.println("Range 3.2");
                    FadeInOut(1);
                }
                break;
                case 2:
                {
                    // Serial.println("Range 3.3");
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



void redBasic(int i) 
{
    // Serial.println("testInRange 1.1");
    for(int i=0; i<NUMPIXELS; i++)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(255);
            Blue_Value = random(0);
            Green_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();    
            Serial.println("Red Basic");
        }
        else
            Serial.println("Default Red Basic");
    }

}

void greenBasic(int i)
{
    // Serial.println("testInRange 1.2");
    for(int i=0; i<NUMPIXELS; i++)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Blue_Value = random(0);
            Green_Value = random(255);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();    
            Serial.println("Green Basic");
        }
        else
            Serial.println("Default Green Basic");
    }
}

void blueBasic(int i)
{
    // Serial.println("testInRange 1.3");
    for(int i=0; i<NUMPIXELS; i++)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Blue_Value = random(255);
            Green_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();    
            Serial.println("Blue Basic");
        }
        else
            Serial.println("Default Blue Basic");
    }
}

void Red_ForBack_Ward(int i)
{

    for(int i=0; i<NUMPIXELS; i++) 
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(255);
            Green_Value = random(0);
            Blue_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Red Forward");
        }
        else
            Serial.println("Default Red Forward");
            // Serial.println("Default Red");
    }
    pixels.clear();
    for (int i=NUMPIXELS; i > 0; i--)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(255);
            Green_Value = random(0);
            Blue_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Red BackWard");
        }
        else
            Serial.println("Default Red BackWard");
    }
    pixels.clear();
}

void Green_ForBack_Ward(int i)
{
    for(int i=0; i<NUMPIXELS; i++) 
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Green_Value = random(255);
            Blue_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Green ForWard");
        }
        else
            Serial.println("Default Green Forward");
            // Serial.println("Default Red");
    }
    pixels.clear();
    for (int i=NUMPIXELS; i > 0; i--)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Green_Value = random(255);
            Blue_Value = random(0);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Green BackWard");
        }
        else
            Serial.println("Default Green BackWard");
    }
    pixels.clear();
}

void Blue_ForBack_Ward(int i)
{
    for(int i=0; i<NUMPIXELS; i++) 
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Green_Value = random(0);
            Blue_Value = random(255);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Blue ForWard");
        }
        else
            Serial.println("Default Blue Forward");
            // Serial.println("Default Red");
    }
    pixels.clear();
    for (int i=NUMPIXELS; i > 0; i--)
    {
        int stateled = random(2);
        if (stateled==0)
        {
            Red_Value = random(0);
            Green_Value = random(0);
            Blue_Value = random(255);
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
            pixels.show();
            Serial.println("Blue BackWard");
        }
        else
            Serial.println("Default Blue BackWard");
    }
    pixels.clear();
}

void RainBow(int i)
{

    for(int i=0; i<NUMPIXELS; i++) 
        {
            int stateled = random(2);
            if (stateled==0)
            {
                Red_Value = random(0);
                Blue_Value = random(0);
                Green_Value = random(255);
                pixels.setPixelColor((i+1), pixels.Color(25, 0, 25)); // violet
                pixels.setPixelColor((i+3), pixels.Color(255, 0, 255)); // indigo
                pixels.setPixelColor((i+4), pixels.Color(0, 0, 150)); // blue
                pixels.setPixelColor((i+5), pixels.Color(0, 150, 0)); // green 
                pixels.setPixelColor((i+6), pixels.Color(255, 255, 0)); // yellow
                pixels.setPixelColor((i+7), pixels.Color(110, 70, 0)); // orange
                pixels.setPixelColor((i+8), pixels.Color(150, 0, 0)); // red
                pixels.show();    
                Serial.println("RainBow Forward");
            }
            else
                Serial.println("Default Rainbow Forward");
        }
        pixels.clear();
    for (int i=NUMPIXELS; i > 0; i--)
        {
            int stateled = random(2);
            if (stateled==0)
            {
                Red_Value = random(0);
                Blue_Value = random(0);
                Green_Value = random(255);
                pixels.setPixelColor((i+1), pixels.Color(25, 0, 25)); // violet
                pixels.setPixelColor((i+3), pixels.Color(255, 0, 255)); // indigo
                pixels.setPixelColor((i+4), pixels.Color(0, 0, 150)); // blue
                pixels.setPixelColor((i+5), pixels.Color(0, 150, 0)); // green 
                pixels.setPixelColor((i+6), pixels.Color(255, 255, 0)); // yellow
                pixels.setPixelColor((i+7), pixels.Color(110, 70, 0)); // orange
                pixels.setPixelColor((i+8), pixels.Color(150, 0, 0)); // red
                pixels.show();    
                Serial.println("RainBow Backward");
            }
            else
                Serial.println("Default Rainbow Backward");
        }
        pixels.clear();
}

void FadeInOut(int i)
{
  int i, j;
  for (j = 45; j < 255; j++) 
  {
       for (i = 0; i < pixels.setPixelColor(); i++) 
        {
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
        }
        strip.show();
        delay(10);
  }
  int i, j;
  for (j = 255; j > 45; j--) 
  {
    for (j = 255; j > 45; j--) 
    {
        for (i = 0; i < pixels.setPixelColor(); i++) 
        {
            pixels.setPixelColor(i, pixels.Color(Red_Value, Green_Value, Blue_Value));
        }
        strip.show();
        delay(10);
    }
  }
}

void testRange09(int i)
{
    Serial.println("testInRange 4.3");
}