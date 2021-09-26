#include <Adafruit_NeoPixel.h>
#define PIN 2  
#define NUMPIXELS 10 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void theaterChaseRainbow(int SpeedDelay);
void setup() 
{
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  theaterChaseRainbow(50);
}

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
