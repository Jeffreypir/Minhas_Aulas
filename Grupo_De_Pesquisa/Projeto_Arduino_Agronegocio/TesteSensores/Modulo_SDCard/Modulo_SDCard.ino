/*
======================================================
          TESTE DO MÓDULO SD COM ARDUINO
======================================================

Objetivo:
 - Testar a comunicação entre o Arduino e o módulo SD.
 - Criar um arquivo e escrever uma mensagem de teste.
 - Ler o arquivo e exibir o conteúdo no Monitor Serial.

Conexões (para módulos SD comuns):
 - CS  -> Pino 10  (Chip Select)
 - SCK -> Pino 13  (Clock)
 - MOSI -> Pino 11 (Dados para o SD)
 - MISO -> Pino 12 (Dados do SD para o Arduino)
 - VCC -> 5V
 - GND -> GND

*OBS: Alguns módulos usam 3.3V. Verifica o modelo  modelo.*

Autor: Jefferson Bezerra dos Santos
Data: Outubro de 2025
*/

#include <SPI.h>
#include <SD.h>

const int pinoCS = 10;   // Pino Chip Select (CS) do módulo SD

void setup() {
  Serial.begin(9600);
  Serial.println("=== TESTE DO MÓDULO SD ===");

  // Inicia comunicação com o cartão SD
  Serial.print("Iniciando o cartão SD... ");
  if (!SD.begin(pinoCS)) {
    Serial.println("FALHA! Verifique conexões e formato do cartão.");
    while (true); // trava o programa
  }
  Serial.println("CARTÃO SD INICIALIZADO COM SUCESSO!");
  Serial.println("----------------------------------");

  // Cria (ou abre) um arquivo no cartão
  File arquivo = SD.open("teste.txt", FILE_WRITE);

  if (arquivo) {
    Serial.println("Gravando mensagem de teste no arquivo...");
    arquivo.println("Teste de gravacao no modulo SD com Arduino!");
    arquivo.println("Tudo funcionando corretamente!");
    arquivo.close(); // fecha o arquivo
    Serial.println("Mensagem gravada com sucesso!");
  } else {
    Serial.println("Erro ao criar ou abrir o arquivo.");
  }

  // Agora abre o arquivo novamente para leitura
  Serial.println("\nLendo o arquivo 'teste.txt':");
  arquivo = SD.open("teste.txt");
  if (arquivo) {
    while (arquivo.available()) {
      Serial.write(arquivo.read()); // exibe o conteúdo do arquivo
    }
    arquivo.close();
  } else {
    Serial.println("Nao foi possivel abrir o arquivo para leitura.");
  }

  Serial.println("\n----------------------------------");
  Serial.println("Teste concluido!");
}

void loop() {
  // Nada a fazer no loop — teste é executado apenas uma vez.
}

