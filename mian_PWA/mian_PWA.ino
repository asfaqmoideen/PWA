 #include "DHT.h" 
 #define DHT_PIN 2
 #define SOILMOISTURE_PIN A0
 DHT dht(DHT_PIN,DHT11);

 void setup()  
 {  
  delay(1000);
  Serial.begin(115200);  
  Serial.println();
  Serial.print("Plan Watering Automation");
  Serial.print("Initializing..;");
  pinMode(SOILMOISTURE_PIN, INPUT);
  pinMode(DHT_PIN, INPUT);
 }  
 void loop()  
 {  
   int soilValue = analogRead(SOILMOISTURE_PIN);
   displayDataInSerialMonitor(soilValue);  
   delay(1000);  
 }

void displayDataInSerialMonitor(int soilValue)
{
  Serial.print("Temperature in C:");  
  Serial.println((dht.readTemperature( )));  
  Serial.print("Humidity in C:");  
  Serial.println((dht.readHumidity()));

  Serial.print("Soil Moisture Percenatge");
  Serial.println();
  Serial.print("Soil Moisture in Analog Value");
  Serial.println(soilValue);
}
