
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

// Tamanho do display (verifique se é 128x64 ou 128x32)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Objeto display (I2C padrão)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  delay(100);

  // Inicializa o display no endereço 0x3C (padrão da maioria dos módulos)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar display SSD1306"));
    for (;;); // trava o código se falhar
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println("Display OLED I2C");
  display.setTextSize(2);
  display.setCursor(10, 30);
  display.println("OK!");
  display.display();
}

void loop() {
  // Exemplo simples: contador
  static int i = 0;
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Contador:");

  display.setTextSize(2);
  display.setCursor(40, 25);
  display.println(i);

  display.display();
  delay(1000);
  i++;
}

