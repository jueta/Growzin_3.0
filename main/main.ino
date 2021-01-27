//Bibliotecas de conexao wifi
#include <WiFi.h>
#include <HTTPClient.h>

//Bibliotecas do AutoConnect
#include <AutoConnect.h>
#include <WebServer.h>

//Bibliotecas sensor de temperatura
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>  //Vem no Arduino já

//Configuracoes Temperatura
#define ONE_WIRE_BUS 4 //variavel do pino 4 que esta plugado o Sensor de Temperatura
OneWire oneWire(ONE_WIRE_BUS); //Instacia o Objeto oneWire e Seta o pino do Sensor para iniciar as leituras
DallasTemperature temperature_sensor(&oneWire); //Repassa as referencias do oneWire para o Sensor Dallas (DS18B20)



//Configuracoes do Autoconnect
WebServer Server;
AutoConnect Portal(Server);
void rootPage() {
  char content[] = "Hello, world";
  Server.send(200, "text/plain", content);
}

String systemURL = "";





void setup() {
  delay(1000);
  Serial.begin(115200);
  Server.on("/", rootPage);
  if (Portal.begin()) {
    Serial.println("HTTP server:" + WiFi.localIP().toString());
  }
}
  



void loop() {

    
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

   //Sensor de Temperatura
   temperature_sensor.requestTemperatures();
   float temp=temperature_sensor.getTempCByIndex(0);
   Serial.print("Temperatura : ");
   Serial.println(temp); 
   
   
   HTTPClient http;   
  
   http.begin(systemURL+"?temperature="+String(temp));  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
   String body = "Oi";
   int httpResponseCode = http.POST(body);   //Send the actual POST request
  
   if(httpResponseCode>0){

    String response = http.getString();                       //Get the response to the request
  
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
  
   }else{
  
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  
   }
  
   http.end();  //Free resources
  
 }else{
  
    Serial.println("Error in WiFi connection");   
  
 }
  
  delay(300000);  //Send a request every 5 minute
}
