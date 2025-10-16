
/*==================== PROGRAM ==============================
 * Program: Teste_Sensor_HD38
 * Date of Create: 14/10/2025
 * Update in: 14/10/2025
 * Author: Jefferson Bezerra dos Santos
 * Description: Programa para testar o sensor de umidade do solo HD-38.
 *              O código realiza a leitura analógica do sensor,
 *              converte o valor em porcentagem de umidade e exibe
 *              os resultados no Monitor Serial.
 *===========================================================
 */

/*==================== ESTRUTURA DE PINOS ====================
 * HD-38 → Arduino
 * ----------------
 * VCC   → 5V
 * GND   → GND
 * AOUT  → A0  (Saída analógica)
 * DOUT  → Não utilizado neste teste
 * ==========================================================
 */

#include <Arduino.h>          // Biblioteca base do Arduino

const int pinoSensor = A0;    // Define o pino analógico conectado à saída AOUT do sensor HD-38
int leituraSensor;            // Variável para armazenar a leitura bruta (0–1023)
int umidadePercentual;        // Variável para armazenar o valor convertido em porcentagem (0–100%)

void setup() {
  Serial.begin(9600);         // Inicializa a comunicação serial a 9600 bps
  Serial.println("Leitura do Sensor de Umidade do Solo HD-38");
}

void loop() {
  leituraSensor = analogRead(pinoSensor);  // Realiza a leitura analógica do sensor (retorna valor de 0 a 1023)

  // Converte o valor lido em porcentagem de umidade
  // Solo seco ≈ 1023 (tensão alta)
  // Solo úmido ≈ 0   (tensão baixa)
  umidadePercentual = map(leituraSensor, 1023, 0, 0, 100);

  // Exibe os resultados no Monitor Serial
  Serial.print("Valor bruto (0-1023): ");
  Serial.print(leituraSensor);
  Serial.print("  |  Umidade do solo: ");
  Serial.print(umidadePercentual);
  Serial.println("%");

  delay(2000);  // Aguarda 2 segundos antes da próxima leitura
}

