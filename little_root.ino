#include <Adafruit_NeoPixel.h>

#define AMBIENTH_LIGHT_SEN A0
#define TEMPERATUR_SEN A1
#define SOLOR_PANEL_SEN A2
#define HUMIDITY_SEN A3

#define TILT_PIN 8
#define ULTRA_SO_TRIGER_PIN 6
#define ULTRA_SO_ECHO_PIN 5
#define VIBRATE_MOTOR_PIN 9

#define NUMPIXELS 1
#define PIN 3
float TempValue, TempValueC, TempValuemv;
float HumValue, HumValueC, HumValuemv; 
Adafruit_NeoPixel jewel = Adafruit_NeoPixel(NUMPIXELS,PIN, NEO_GRB + NEO_KHZ800);

class Data
{
    int light;
    int temperature;
    int panneau_solaire;
  	long ground_quality;
  	int humidity;
  	int tilt;
};
Data array[100] = {}; 
void setup()
{

  Serial.begin(9600);
  pinMode(AMBIENTH_LIGHT_SEN,INPUT); 
  pinMode(TEMPERATUR_SEN,INPUT); 
  pinMode(SOLOR_PANEL_SEN,INPUT); 
  pinMode(HUMIDITY_SEN,INPUT); 
   
  pinMode(TILT_PIN,INPUT); 
  pinMode(VIBRATE_MOTOR_PIN,INPUT); 
  pinMode(ULTRA_SO_TRIGER_PIN,OUTPUT); 
  pinMode(ULTRA_SO_ECHO_PIN,INPUT); 
}

void loop()
{
  Serial.println("Data");
  Serial.println("-------------------");

  int ambient_light_read = ambient_light_func();
  Serial.println(ambient_light_read);
  
  int solor_panel_read = solor_panel_func();
  Serial.println(solor_panel_read);
  
  int tilt_read = tilt_func();
  Serial.println(tilt_read);
  
  TempValueC = Temperatur_func();
  Serial.println(TempValueC);
  
  HumValueC = Humidity_func();
  Serial.println(HumValueC);
  
  long ground_fertility = (ground_fertility_func()*100)/326;
  Serial.println(ground_fertility);
  
  digitalWrite(VIBRATE_MOTOR_PIN, HIGH);
  delay(100); 
  digitalWrite(VIBRATE_MOTOR_PIN, LOW);
  

  Serial.println("*******************");
  Serial.println("Information :");
  Serial.println("*******************");
  int problem = 0;
  
  if(ambient_light_read <= 25){
    problem = problem < 1 ? 1 : problem ;
    Serial.println("FAIBLE LUMINOSITE");

  }
  
  if(solor_panel_read <= 900){
    problem = problem < 2 ? 2 : problem ;
    Serial.println("Panneau solaire mal eclaire , Risque de coupure");
  }
  
  if(tilt_read == 0){
    problem = problem < 2 ? 2 : problem ;
    Serial.println("Little Root Deracine");
  }
  
  if(TempValueC <= 5){
    problem = problem < 1 ? 1 : problem ;
    Serial.println("Il Fait Trop froids");
  }
  if(TempValueC >= 40){
    problem = problem < 1 ? 1 : problem ;
    Serial.println("Il Fait Trop Chaud");
  }
  
  if(HumValueC <= 10){
    problem = problem < 1 ? 1 : problem ;
    Serial.println("Pas assez d'humidite");
  }
  if(HumValueC >= 110){
    problem = problem < 1 ? 1 : problem ;
    Serial.println("Trop d'humidite");
  }
  
  if(ground_fertility <= 25){
    problem = problem < 2 ? 2 : problem ;
    Serial.println("Little Root Deracine");
  }
  Serial.print("problem :");
  Serial.println(problem);
  Serial.println("*******************");
  Serial.println("-------------------");
  int red= 0;
  int green = 255;
  int blue = 0;
  if (problem == 0){
		green = 255;
  }
  else if(problem == 1){
    red= 255;
  green = 255;
  }
  
  else if(problem == 2){
    red= 255;
    green = 0;
  }
   jewel.setPixelColor(0, red, green, blue);
  	jewel.show();
    delay(1000);
    jewel.setPixelColor(0, 0, 0, 0);
    jewel.show();
    delay(1000);

}

int ambient_light_func ()
{
  int ambient_light_read = analogRead(AMBIENTH_LIGHT_SEN);
  Serial.print("Ambienth Light : ");
  return ambient_light_read;
}

int solor_panel_func ()
{
  int solor_panel_read = analogRead(SOLOR_PANEL_SEN);
  Serial.print("Solor Panel : ");
  return solor_panel_read;
}


int tilt_func ()
{
  int tilt_read = digitalRead(TILT_PIN);
  Serial.print("Tilt Read : ");
  return tilt_read;
}
 
float Temperatur_func ()
{
  TempValue=analogRead(TEMPERATUR_SEN); 
  TempValuemv=TempValue*5000/1024;
  TempValueC=(TempValuemv/10)+(-50);
  Serial.print("Temperature  : ");
  return TempValueC;
  
}

float Humidity_func ()
{
  HumValue=analogRead(HUMIDITY_SEN); 
  HumValuemv=HumValue*5000/1024;
  HumValueC=(HumValuemv/10)+(-9.77);
  Serial.print("Humidity  : ");
  return HumValueC;
  
}

int ground_fertility_func ()
{
  digitalWrite(ULTRA_SO_TRIGER_PIN, LOW);
  delay(1);
  digitalWrite(ULTRA_SO_TRIGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_SO_TRIGER_PIN, LOW);
  
  long duration = pulseIn(ULTRA_SO_ECHO_PIN,HIGH);
  int distance = duration *0.017;
  Serial.print("Ground Fertility : ");
  return distance;
  
}
