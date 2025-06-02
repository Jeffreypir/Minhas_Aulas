import os
import json
import subprocess
import platform

# Solicita o nome do projeto
projeto = input("Nome do projeto: ")

# Criar diretório do projeto
os.makedirs(f"{projeto}/.vscode", exist_ok=True)

# Função para verificar se o arduino-cli está instalado
def verificar_arduino_cli():
    try:
        resultado = subprocess.run(["arduino-cli", "version"], capture_output=True, text=True)
        if "arduino-cli" in resultado.stdout:
            print("✅ Arduino CLI encontrado!")
            return True
    except FileNotFoundError:
        print("⚠️ Arduino CLI não encontrado! Instale-o antes de continuar.")
    return False

# Função para detectar a placa e a porta do Arduino
def detectar_placa_e_porta():
    fqbn = "arduino:avr:uno"
    porta = "COM3"
    try:
        resultado = subprocess.run(["arduino-cli", "board", "list"], capture_output=True, text=True)
        linhas = resultado.stdout.split("\n")
        for linha in linhas:
            if "arduino" in linha.lower():
                partes = linha.split()
                porta = partes[0]  # Primeira parte geralmente é a porta (ex: COM3 ou /dev/ttyUSB0)
                fqbn = partes[-1]  # Última parte geralmente é o fqbn
                break
    except Exception as e:
        print(f"⚠️ Erro ao detectar placa e porta: {e}")
    print(f"🔌 Placa detectada: {fqbn}")
    print(f"🔌 Porta detectada: {porta}")
    return fqbn, porta

# Função para executar comandos de forma compatível com Windows
def executar_comando(comando):
    try:
        if platform.system() == "Windows":
            # No Windows, usamos subprocess.run com shell=True
            subprocess.run(comando, shell=True, check=True)
        else:
            # No Linux/Mac, podemos executar diretamente
            subprocess.run(comando, check=True)
        return True
    except subprocess.CalledProcessError as e:
        print(f"⚠️ Erro ao executar comando: {e}")
        return False

# Verifica se o arduino-cli está instalado antes de continuar
if not verificar_arduino_cli():
    exit(1)

# Detecta a placa e a porta do Arduino
fqbn, porta_arduino = detectar_placa_e_porta()

# Criar tasks.json com a placa e a porta detectadas
tasks = {
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar Arduino com Make",
            "type": "shell",
            "command": "make compile",
            "group": {"kind": "build", "isDefault": True},
            "problemMatcher": []
        },
        {
            "label": "Upload para Arduino com Make",
            "type": "shell",
            "command": "make upload",
            "group": {"kind": "test", "isDefault": True},
            "problemMatcher": []
        },
        {
            "label": "Gerar compile_commands.json",
            "type": "shell",
            "command": "make generate_commands",
            "problemMatcher": []
        }
    ]
}

# Salvar arquivo tasks.json
with open(f"{projeto}/.vscode/tasks.json", "w") as f:
    json.dump(tasks, f, indent=4)

# Criar Makefile com suporte para gerar compile_commands.json
makefile_content = f"""
BOARD={fqbn}
PORT={porta_arduino}
SKETCH={projeto}.ino
BUILD_DIR=build

compile:
\tarduino-cli compile --fqbn $(BOARD) $(SKETCH)

upload:
\tarduino-cli upload -p $(PORT) --fqbn $(BOARD) $(SKETCH)

generate_commands:
\tarduino-cli compile --fqbn $(BOARD) --build-path $(BUILD_DIR) $(SKETCH)
{"\tcopy $(BUILD_DIR)\\compile_commands.json ." if platform.system() == "Windows" else "\tcp $(BUILD_DIR)/compile_commands.json ."}
\trmdir /s /q $(BUILD_DIR) 2>nul || rm -rf $(BUILD_DIR)
"""

with open(f"{projeto}/Makefile", "w") as f:
    f.write(makefile_content)

# Criar workflow.yml para automação
workflow_content = f"""
name: Arduino CI/CD

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout código
        uses: actions/checkout@v2
      
      - name: Instalar Arduino CLI
        run: |
          curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
          arduino-cli core update-index
          arduino-cli core install {fqbn.split(':')[0]}:{fqbn.split(':')[1]}
      
      - name: Compilar Sketch
        run: make compile
      
      - name: Gerar compile_commands.json
        run: make generate_commands
      
      - name: Upload para Arduino
        run: make upload
"""

os.makedirs(f"{projeto}/.github/workflows", exist_ok=True)
with open(f"{projeto}/.github/workflows/arduino-ci.yml", "w") as f:
    f.write(workflow_content)

# Criar um arquivo .ino básico
with open(f"{projeto}/{projeto}.ino", "w") as f:
    f.write("""\
#include <Arduino.h>
void setup() {
    Serial.begin(9600);
    Serial.println("Arduino iniciado!");
}

void loop() {
    // Código aqui
}
""")

# Executar a geração do compile_commands.json automaticamente
print("\n🔧 Gerando compile_commands.json...")
if executar_comando(f"cd {projeto} && make generate_commands"):
    print("✅ compile_commands.json gerado com sucesso!")
else:
    print("⚠️ Falha ao gerar compile_commands.json")

print(f"\n🎉 Projeto {projeto} criado com sucesso! 🚀")

import os
import json
import subprocess
import platform
from pathlib import Path

# [...] (mantenha todo o código existente até a criação do arquivo .ino)

# ADICIONE ESTA FUNÇÃO ANTES DA EXECUÇÃO DO SCRIPT PRINCIPAL
def criar_arquivo_clangd(projeto):
    """Cria o arquivo .clangd com configurações para Arduino"""
    user_path = str(Path.home())
    
    clangd_content = f"""CompileFlags:
    CompileFlags:
  Add:    
    # Caminhos principais (usando / ou \\)
    - -IC:/Users/Jeffrey24/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino
    - -IC:\\Users\\Jeffrey24\\AppData\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\1.8.6\\variants\\standard
    
    # Bibliotecas padrão
    - -IC:/Users/Jeffrey24/AppData/Local/Arduino15/libraries/Arduino_BuiltIn/src
    - -IC:\\Users\\Jeffrey24\\AppData\\Local\\Arduino15\\libraries\\Ethernet\\src
    
    # Bibliotecas locais
    - -IC:/Users/Jeffrey24/Documents/Arduino/libraries/LiquidCrystal/src
    - -IC:\\Users\\Jeffrey24\\Documents\\Arduino\\libraries\\Servo\\src
    
    # Bibliotecas de hardware
    - -IC:/Users/Jeffrey24/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/libraries/SPI/src
      """
    
    with open(f"{projeto}/.clangd", "w", encoding="utf-8") as f:
        f.write(clangd_content)

# [...] (mantenha a geração do compile_commands.json)

# ADICIONE ESTA LINHA ANTES DA MENSAGEM FINAL
criar_arquivo_clangd(projeto)
print("✅ Arquivo .clangd configurado com sucesso!")

# [...] (mantenha o resto do código existente)
