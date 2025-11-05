/*==================== PROGRAM ==============================
 * Program: Teste_Sensor_DHT11_OLED
 * Date of Create: 14/10/2025
 * Update in: 19/10/2025
 * Author: Jefferson Bezerra dos Santos
 * Description: Teste do sensor DHT11 com exibição no display OLED SSD1306 (I2C).
 *              Mostra temperatura e umidade no display.
 *              O LED acende quando a umidade >= 58%.
 *===========================================================
 */

/*==================== ESTRUTURA DE PINOS ====================
 * DHT11 → Arduino
 * ----------------
 * VCC   → 5V
 * DATA  → Pino A2
 * GND   → GND
 *
 * OLED SSD1306 (I2C)
 * -------------------
 * VCC   → 5V
 * GND   → GND
 * SDA   → A4
 * SCK   → A5
 * ==========================================================
 */

#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// === Configurações do DHT11 ===
#define DHTPIN A2
#define DHTTYPE DHT11
#define LED 13
DHT dht(DHTPIN, DHTTYPE);

// === Configurações do OLED ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste do Sensor DHT11 com OLED");

  dht.begin();

  // Inicializa o display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar display SSD1306!"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("Sensor DHT11");
  display.setCursor(10, 35);
  display.println("Inicializando...");
  display.display();
  delay(2000);
}

void loop() {
  delay(2000);

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler o sensor DHT11!");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(10, 25);
    display.println("Erro na leitura!");
    display.display();
    return;
  }

  // Controle do LED com base na umidade
  if (umidade >= 58) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Exibe no Serial (opcional)
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" %  |  Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // === Exibe no OLED ===
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(10, 0);
  display.println("Leitura do DHT11");

  display.setTextSize(2);
  display.setCursor(10, 20);
  display.print("T:");
  display.print(temperatura, 1);
  display.print("C");

  display.setCursor(10, 45);
  display.print("U:");
  display.print(umidade, 1);
  display.print("%");

  display.display();
}

