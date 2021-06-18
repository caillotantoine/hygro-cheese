#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 10
#define DHTTYPE DHT11

SoftwareSerial disp(6, 7);
DHT dht(DHTPIN, DHTTYPE);

char str[4] = {0};
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  disp.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  int H = (int) h;
  int T = (int) t;

  disp.write("v");
  
  if(state) 
  {
    disp.write("h");
    sprintf(str, " %2d", H);
  }
  else
  {
    disp.write("t");
    sprintf(str, " %2d", T);
  }
  state ^= 1;
  
  disp.write(str);
  Serial.println(str);
  delay(5000);
}
