
/*==================== PROGRAM ==============================
 * Program: <+name+>
 * Date of Create: <+date+>
 * Update in: <+update+>
 * Author:Jefferson Bezerra dos Santos
 * Description: <+description+>
 *===========================================================
 */

#include <Arduino.h>
#include <Servo.h>

Servo garra;           // servo da garra
const int trigPin = 9;
const int echoPin = 10;

const int GARRA_ABERTA = 10;   // ajuste conforme montagem (0..180)
const int GARRA_FECHADA = 90;  // ajuste conforme montagem
int threshold_cm = 12;         // distância para fechar (cm)

bool modoAuto = true;

void setup() {
  Serial.begin(9600);
  garra.attach(3);
  garra.write(GARRA_ABERTA);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Garra pronta. Modo AUTO.");
  Serial.println("Comandos Serial: open, close, auto, stop, set X (cm)");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.equalsIgnoreCase("open")) {
      modoAuto = false;
      abrirGarra();
      Serial.println("Comando: abrir");
    } else if (cmd.equalsIgnoreCase("close")) {
      modoAuto = false;
      fecharGarra();
      Serial.println("Comando: fechar");
    } else if (cmd.equalsIgnoreCase("auto")) {
      modoAuto = true;
      Serial.println("Modo AUTOMÁTICO ativado");
    } else if (cmd.equalsIgnoreCase("stop")) {
      modoAuto = false;
      Serial.println("Modo MANUAL (parado)");
    } else if (cmd.startsWith("set ")) {
      int val = cmd.substring(4).toInt();
      if (val > 0) {
        threshold_cm = val;
        Serial.print("Limiar ajustado para ");
        Serial.print(threshold_cm);
        Serial.println(" cm");
      }
    } else {
      Serial.print("Comando desconhecido: ");
      Serial.println(cmd);
    }
  }

  if (modoAuto) {
    int dist = medirDistancia();
    Serial.print("Distância: ");
    Serial.print(dist);
    Serial.println(" cm");

    if (dist > 0 && dist <= threshold_cm) {
      fecharGarra();
      Serial.println("Objeto detectado — fechando garra");
      delay(600); // aguarda pegar
      // opcional: manter fechada por X ms ou adicionar lógica adicional
    } else {
      abrirGarra();
    }
    delay(200);
  } else {
    delay(50); // modo manual: loop leve
  }
}

int medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms
  if (duration == 0) return -1; // sem leitura
  int dist = (int)(duration * 0.034 / 2);
  return dist;
}

void abrirGarra() {
  garra.write(GARRA_ABERTA);
}

void fecharGarra() {
  garra.write(GARRA_FECHADA);
}

