#include "DHT.h"

const int pino_dht = 8; // pino do sensor DHT
float temperatura; // Variável para armazenar a temperatura
float umidade; // Variável para armazenar a umidade
DHT dht(pino_dht, DHT11); // Define o pino e o tipo de sensor DHT

void setup() {
  Serial.begin(9600); // Inicia a comunicação Serial a 9600 bps
  dht.begin(); // Inicializa o sensor DHT

  Serial.println("===================================");
  Serial.println(" Bem-vindo ao MonteCarloDigital ");
  Serial.println(" Monitoramento de Temperatura e Umidade");
  Serial.println("===================================");
}

void loop() {
  delay(2000); // Aguarda 2 segundos entre as leituras

  // Lê os valores do sensor
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  // Verifica se a leitura foi bem-sucedida
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("[MonteCarloDigital] ERRO: Falha na leitura do sensor DHT!");
  } else {
    // Exibe os valores lidos
    Serial.println("===================================");
    Serial.println(" MonteCarloDigital - Dados do Sensor");
    Serial.print(" Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print(" Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");
    Serial.println("===================================");
  }
}
