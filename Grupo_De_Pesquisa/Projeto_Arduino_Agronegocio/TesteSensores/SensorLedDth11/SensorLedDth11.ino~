/*==================== PROGRAM ==============================
 * Program: Teste_Sensor_DHT11
 * Date of Create: 14/10/2025
 * Update in: 2025-10-14 09:21:28
 * Author: Jefferson Bezerra dos Santos
 * Description: Programa simples para testar o sensor DHT11.
 *              O código lê a temperatura e a umidade do ar
 *              e exibe os valores no Monitor Serial.
 *              Usando Led para da o sinal de resposta 
 *===========================================================
 */

/*==================== ESTRUTURA DE PINOS ====================
 * DHT11 → Arduino
 * ----------------
 * VCC   → 5V
 * DATA  → Pino Digital 10
 * Void  -> Não usar esse pino do sensor
 * GND   → GND
 * ==========================================================
 */

#include <Arduino.h>  // Biblioteca base do Arduino
#include "DHT.h"      // Biblioteca do sensor DHT

#define DHTPIN A2       // Define o pino digital onde o sinal DATA do DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo do sensor (DHT11)
#define LED 13

DHT dht(DHTPIN, DHTTYPE); // Cria um objeto 'dht' para manipular o sensor

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);          // Inicializa a comunicação serial a 9600 bps
  Serial.println("Teste do Sensor DHT11");
  dht.begin();                 // Inicializa o sensor DHT11
}

void loop() {
  delay(2000); // Aguarda 2 segundos entre cada leitura (tempo recomendado pelo fabricante)

  // Leitura dos valores de umidade e temperatura
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature(); // Valor em Celsius

  // Verifica se a leitura falhou
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler o sensor DHT11!");
    return;
  }
  if (umidade >= 58) {
    digitalWrite(LED, HIGH);
  
  }else{
    digitalWrite(LED, LOW);
  }

  // Exibe os valores lidos no Monitor Serial
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" %  |  Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}

