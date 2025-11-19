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

  // Inicializa o sensor DS18B20
  sensors.begin();

  // Inicializa o OLED
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
  // Atualiza a leitura do DS18B20
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Imprime no Serial
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" C");

  // ----------- Exibe no OLED -----------
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Temperatura DS18B20");

  display.setTextSize(2);
  display.setCursor(10,30);
  display.print(tempC);
  display.print(" C");

  display.display();

  delay(500);
}

