#include <ArduinoJson.h>
#include "DHT.h"

const int pino_dht = 8;
float temperatura, umidade;
DHT dht(pino_dht, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();

  Serial.println("======================================");
  Serial.println("Bem-vindo ao <<MonteCarloDigital>>");
  Serial.println("Monitoramento de Temperatura e Umidade");
  Serial.println("======================================");
}

void loop(){
  delay(2000);

  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  if(isnan(umidade) || isnan(temperatura)){
    Serial.println("[MonteCarloDigital]:( ERRO: Falha na leitura do sensor DHT!");
  } else{
    StaticJsonDocument<200> doc;
    doc["sensor"] = "DHT11";
    doc["temperatura"] = temperatura;
    doc["umidade"] = umidade;

    String json;
    serializeJson(doc, json);
    Serial.println(json);
  }
}
