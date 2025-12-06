
/*==================== PROGRAM ==============================
* Program: <+name+>
* Date of Create: <+date+>
* Update in: <+update+>
* Author:Jefferson Bezerra dos Santos
* Description: <+description+>
*===========================================================
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------------- DS18B20 ----------------------------
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ---------------------- OLED -------------------------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Endereço I2C padrão do SSD1306 é 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  sensors.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Erro ao iniciar o OLED"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Iniciando...");
  display.display();
  delay(1000);
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Conversões
  float tempF = tempC * 9.0 / 5.0 + 32.0;     // Fahrenheit
  float tempK = tempC + 273.15;              // Kelvin

  // Saída Serial
  Serial.print("Celsius: "); Serial.print(tempC); Serial.print(" °C, ");
  Serial.print("Fahrenheit: "); Serial.print(tempF); Serial.print(" °F, ");
  Serial.print("Kelvin: "); Serial.print(tempK); Serial.println(" K");

  // ----------- Exibe no OLED -----------
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("DS18B20 Temperatura");

  display.setTextSize(1);
  display.setCursor(0,20);
  display.print("C: ");
  display.print(tempC);
  display.println(" Celsius");

  display.setCursor(0,35);
  display.print("F: ");
  display.print(tempF);
  display.println(" Fahrenheit");

  display.setCursor(0,50);
  display.print("K: ");
  display.print(tempK);
  display.println(" Kelvin");

  display.display();

  delay(500);
}

