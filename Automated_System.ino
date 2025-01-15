#include <WiFi.h>
#include <dht11.h>
//#define DHT11PIN 17
#define SteamPin 35
#define SoilHumidityPin 32
#define WaterLevelPin 33
#define RelayPin 25
#define BuzzerPin 16
#define ButtonPin 5
int value = 0;
//dht11 DHT11;



const char* ssid = "VM7012826";
const char* password = "Rmpj6viujjjcyi5k";

void setup() {
  // put your setup code here, to run once:
  //float chk = DHT11.read(DHT11PIN);
  Serial.begin(9600);
  //Serial.println(DHT11LIB_VERSION);
  //DHT11.read(DHT11PIN.)
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WIFI. Please wait");
  }
  Serial.println("Connected to WIFI");
  Serial.println(WiFi.localIP());
  pinMode(RelayPin,OUTPUT);
  pinMode(SoilHumidityPin,INPUT);
  pinMode(WaterLevelPin,INPUT);
  pinMode(BuzzerPin,OUTPUT);
  pinMode(ButtonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //float chk = DHT11.read(SteamPin);
  float soilhumidity = analogRead(SoilHumidityPin);
  float waterlevel = analogRead(WaterLevelPin);
  float ReadValue = digitalRead(ButtonPin);
  Serial.println(soilhumidity);
  Serial.println(waterlevel);
  //pinMode(soilhumidity, INPUT);
  //pinMode(waterlevel, INPUT);
  
  if (ReadValue == 0) {
    //Eliminate the button shake
    delay(10);  
    if (ReadValue == 0) {
      value = !value;
      Serial.print("The current status of the button is : ");
      Serial.println(value);
      Serial.println(value + " alarm muted. Soil humidity or water level too low");
      
      //else{
        //Serial.println(value);
      //}
      
    }
    //Again, determine whether the button is still pressed
    //Pressed: execute the loop; Released: exit the loop to next execution
    while (digitalRead(ButtonPin) == 0); 
  }
  if(500 >= soilhumidity && value == 0)
  {
    tone(BuzzerPin, 532);
    delay(100);
    tone(BuzzerPin, 532);
    delay(100);
    tone(BuzzerPin, 659);
    delay(100);
    noTone(BuzzerPin);
    Serial.println("Soil humidity is too low");
  }
  if(500 >= waterlevel && value == 0)
  {
    tone(BuzzerPin, 411);
    delay(100);
    tone(BuzzerPin, 639);
    delay(100);
    tone(BuzzerPin, 411);
    delay(100);
    noTone(BuzzerPin);
    Serial.println("Water level is too low");
  }
  if(500 >= soilhumidity && waterlevel >= 1000)
  {
    digitalWrite(RelayPin,HIGH);
    delay(400);
    digitalWrite(RelayPin,LOW);
    delay(700);
  }
  //if(1000 >= soilhumidity)
  //{
    //digitalWrite(RelayPin,HIGH);
    //delay(400);
    //digitalWrite(RelayPin,LOW);
    //delay(700);
  //}
 
  
  //Serial.println(soilhumidity);
  delay(2000);
  

}
