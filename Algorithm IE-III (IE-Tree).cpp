//Algorithm IE-III (IE-Tree)
//Arif Dueramae 
#include <Adafruit_NeoPixel.h>
#define PIN 2	
#define NUMPIXELS 48 
int Red_Value = 0, Blue_Value = 0, Green_Value = 0, delayval = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void BouncingBalls_Red(byte red, byte green, byte blue, int BallCount);
void BouncingBalls_Green(byte red, byte green, byte blue, int BallCount);
void BouncingBalls_Blue(byte red, byte green, byte blue, int BallCount);
void Red_ForBack_Ward(int i);
void Green_ForBack_Ward(int i);
void Blue_ForBack_Ward(int i);
void theaterChaseRainbow(int SpeedDelay);
void fadeRGB(int i);
void Twinkle(int i);
void brightenRed();
void darkenBlueRed();
void brightenBlue();
void darkenBlue();
void TwinkleRed(int Count, int SpeedDelay, boolean OnlyOne);
void TwinkleGreen(int Count, int SpeedDelay, boolean OnlyOne);
void TwinkleBlue(int Count, int SpeedDelay, boolean OnlyOne);
int stateRun=0;


void setup() {
      Serial.begin(9600);
      pixels.begin();
}

void loop() 
{
    // read the sensor:
    int sensorPin1 = analogRead(A1);
    int sensorPin2 = analogRead(A2);
    
    // map the sensor 
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
                    Serial.println("Range 1.1");
                    BouncingBalls_Red(0xff,0,0, 3);
                }
                break;
                case 1:
                {
                    Serial.println("Range 1.2");
                    BouncingBalls_Green(0,0xff,0, 3);
                }
                break;
                case 2:
                {
                    Serial.println("Range 1.3");
                    BouncingBalls_Blue(0,0,0xff, 3);
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
                  theaterChaseRainbow(50);
                }
                break;
                case 1:
                {
                    fadeRGB(1);
                }
                break;
                case 2:
                {
                    // Serial.println("Range 3.3");
                    Twinkle(1);
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

// // Mode 1
void BouncingBalls_Red(byte red, byte green, byte blue, int BallCount) 
{
  float Gravity = -9.81;
  int StartHeight = 1;
 
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
 
  for (int i = 0 ; i < BallCount ; i++) 
  {  
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) 
  {
    for (int i = 0 ; i < BallCount ; i++) 
    {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
 
      if ( Height[i] < 0 ) 
      {                      
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();
 
        if ( ImpactVelocity[i] < 0.01 ) 
        {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (NUMPIXELS - 1) / StartHeight);
    }
 
    for (int i = 0 ; i < BallCount ; i++) 
    {

        pixels.setPixelColor(Position[i], pixels.Color(red, green, blue));
    }
    pixels.show();
    Serial.println("BouncingBalls Red");
    pixels.clear();
  }
}

void BouncingBalls_Green(byte red, byte green, byte blue, int BallCount) 
{
  float Gravity = -9.81;
  int StartHeight = 1;
 
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
 
  for (int i = 0 ; i < BallCount ; i++) {  
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
 
      if ( Height[i] < 0 ) {                      
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();
 
        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (NUMPIXELS - 1) / StartHeight);
    }
 
    for (int i = 0 ; i < BallCount ; i++) 
    {

        pixels.setPixelColor(Position[i], pixels.Color(red, green, blue));
    }
    pixels.show();
    Serial.println("BouncingBalls Green");
    pixels.clear();
  }
}
void BouncingBalls_Blue(byte red, byte green, byte blue, int BallCount) 
{
  float Gravity = -9.81;
  int StartHeight = 1;
 
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
 
  for (int i = 0 ; i < BallCount ; i++) {  
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
 
      if ( Height[i] < 0 ) {                      
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();
 
        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (NUMPIXELS - 1) / StartHeight);
    }
 
    for (int i = 0 ; i < BallCount ; i++) 
    {

        pixels.setPixelColor(Position[i], pixels.Color(red, green, blue));
    }
    pixels.show();
    Serial.println("BouncingBalls Blue");
    pixels.clear();
  }
}

//Mode 2
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

//Mode 3
void theaterChaseRainbow(int SpeedDelay) {
  byte *c;
 
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < NUMPIXELS; i=i+3) {
          c = Wheel( (i+j) % 255);
          pixels.setPixelColor(i+q, *c, *(c+1), *(c+2));    //turn every third pixel on
        }
        pixels.show();
       
        delay(SpeedDelay);
       
        for (int i=0; i < NUMPIXELS; i=i+3) {
          pixels.setPixelColor(i+q, 0,0,0);        //turn every third pixel off
        }
    }
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}

void fadeRGB(int i)
{
    brightenRed();
    darkenRed();
    brightenBlue();
    darkenBlue();
}

void brightenRed() 
{
  uint16_t i, j;

  for (j = 45; j < 255; j++) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, j, 0, 0);
    }
    pixels.show();
    Serial.println("Brighten Red");
    Serial.println(j);
    delay(10);
  }
  //delay(1500);
}

void darkenRed() 
{
  uint16_t i, j;

  for (j = 255; j > 45; j--) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, j, 0, 0);
    }
    pixels.show();
    Serial.println("Darken Red");
    Serial.println(j);
    delay(10);
  }
  delay(1500);
}

void brightenGreen() 
{
  uint16_t i, j;

  for (j = 45; j < 255; j++) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, 0, j, 0);
    }
    pixels.show();
    Serial.println("Brighten Green");
    Serial.println(j);
    delay(10);
  }
  //delay(1500);
}

void darkenGreen() 
{
  uint16_t i, j;

  for (j = 255; j > 45; j--) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, 0, j, 0);
    }
    pixels.show();
    Serial.println("Darken Green");
    Serial.println(j);
    delay(10);
  }
  delay(1500);
}

void brightenBlue() 
{
  uint16_t i, j;

  for (j = 45; j < 255; j++) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, 0, 0, j);
    }
    pixels.show();
    Serial.println("Brighten Blue");
    Serial.println(j);
    delay(10);
  }
  //delay(1500);
}

void darkenBlue() 
{
  uint16_t i, j;

  for (j = 255; j > 45; j--) 
  {
    for (i = 0; i < pixels.numPixels(); i++) 
    {
      pixels.setPixelColor(i, 0, 0, j);
    }
    pixels.show();
    Serial.println("Darken Blue");
    Serial.println(j);
    delay(10);
  }
  delay(1500);
}

void Twinkle(int i)
{
    TwinkleRed(NUMPIXELS, 100, false);
    TwinkleGreen(NUMPIXELS, 100, false);
    TwinkleBlue(NUMPIXELS, 100, false);
}

void TwinkleRed(int Count, int SpeedDelay, boolean OnlyOne) 
{
    pixels.clear();
  for (int i=0; i<Count; i++) 
  {

        pixels.setPixelColor(random(i), pixels.Color(random(255), 0, 0));
        pixels.show();
        Serial.println("Twinkle Red"); 
        delay(SpeedDelay);
        if(OnlyOne) 
        {
        pixels.clear();
        }
   }
  delay(SpeedDelay);
}
void TwinkleGreen(int Count, int SpeedDelay, boolean OnlyOne) 
{
    pixels.clear();
  for (int i=0; i<Count; i++) 
  {
        pixels.setPixelColor(random(i), pixels.Color(0, random(255), 0));
        pixels.show();
        Serial.println("Twinkle Green"); 
        delay(SpeedDelay);
        if(OnlyOne) 
        {
        pixels.clear();
        }
   }
  delay(SpeedDelay);
}
void TwinkleBlue(int Count, int SpeedDelay, boolean OnlyOne) 
{
    pixels.clear();
  for (int i=0; i<Count; i++) 
  {
        pixels.setPixelColor(random(i), pixels.Color(0, 0, random(255)));
        pixels.show();
        Serial.println("Twinkle Blue"); 
        delay(SpeedDelay);
        if(OnlyOne) 
        {
        pixels.clear();
        }
   }
  delay(SpeedDelay);
}


