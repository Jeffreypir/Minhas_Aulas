#include <Arduino.h>
#include <SerialJeff.h>

// Pino analogico conectado ao sensor 

const int sensorPin = A0;

void setup() {
    Serial.begin(9600);
    Serial.print("Iniciando a leitura do TCRT5000");
}

void loop() {
    // Le o valor do sensor 
    int valor = analogRead(sensorPin);

    // Mostra no monitor Serial 

    Serial.print("Valor lido:  ");
    Serial.println(valor);
    if (valor <= 900) {
    Serial.println("Água limpa ");
        
    } else {
    Serial.println("Água turva ");
        
    }

    // Aguarda 0.5 segundos 
    delay(500);

}
