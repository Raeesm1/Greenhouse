#include <WiFi.h>
#include <dht11.h>
//#define DHT11PIN 17
#define SteamPin 35
#define SoilHumidityPin 32
#define WaterLevelPin 33
#define RelayPin 25
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
}

void loop() {
  // put your main code here, to run repeatedly:
  //float chk = DHT11.read(SteamPin);
  float soilhumidity = analogRead(SoilHumidityPin);
  float waterlevel = analogRead(WaterLevelPin);
  Serial.println(soilhumidity);
  //pinMode(soilhumidity, INPUT);
  //pinMode(waterlevel, INPUT);
  
  
  
  //if(5000 >= soilhumidity)
  //{
    digitalWrite(RelayPin,HIGH);
    delay(400);
    digitalWrite(RelayPin,LOW);
    delay(700);
  //}
 
  
  //Serial.println(soilhumidity);
  delay(2000);
  

}
