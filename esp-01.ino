#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D1 // Digital pin D1
#define DHTTYPE DHT11 // DHT 11
//Configure o Auth Token enviado para o email
char auth[] = "..."; //Token do novo

// suas credenciais de wifi
// senha "" para redes livres
char ssid[] = "..."; //node da rede wifi
char pass[] = "..."; //senha da rede wifi
DHT dht(DHTPIN, DHTTYPE);
// No app para difinir a frquencia que o indicador é atualizado
configure PUSH
void setup(){
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
dht.begin();
}
void loop(){
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t)) {
 Serial.println("Falha na leitura do sensor!");

}
Blynk.virtualWrite(V5, h); //V5 para umidade
Blynk.virtualWrite(V6, t); //v6 para temperatura
Blynk.run(); // inicializa o Blynk
delay(1000);
}
