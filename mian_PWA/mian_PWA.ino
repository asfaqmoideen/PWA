 #include "DHT.h" 
 #define DHT_PIN 2
 #define SOILMOISTURE_PIN A0
 DHT dht(DHT_PIN,DHT11);
   
 void setup()  
 {  
  delay(1000);
  Serial.begin(115200);  
  Serial.println();
  pinMode(SOILMOISTURE_PIN, INPUT);
  pinMode(DHT_PIN, INPUT);
 }  
 void loop()  
 {  
   displayDHTDataInSerialMoinotor();
   displaySoilDataInSerialMonitor();  
   delay(1000);  
 }

 void displayDHTDataInSerialMoinotor()
 {
   Serial.print("Temperature in C:");  
   Serial.println((dht.readTemperature( )));  
   Serial.print("Humidity in C:");  
   Serial.println((dht.readHumidity()));  
 }

void displaySoilDataInSerialMonitor()
{
  int soilValue = analogRead(SOILMOISTURE_PIN);
  double soilMoisturePercenatge = 100 - ((soilValue/1024)*100) ;
  Serial.print("Soil Moisture Percenatge");
  Serial.println(soilMoisturePercenatge);
  Serial.print("Soil Moisture in Analog Value");
  Serial.println(soilValue);
}
