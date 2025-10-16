# ==========================================================
# Makefile para Arduino CLI
# Gerado automaticamente por CreateMakefile()
# ==========================================================

ARDUINO_CLI = arduino-cli.exe
BOARD = arduino:avr:uno
PORT = COM6
SKETCH = Modulo_SDCard.ino
BUILD_DIR = build

compile:
	$(ARDUINO_CLI) compile --fqbn $(BOARD) $(SKETCH)

upload: compile
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(BOARD) $(SKETCH)

usb: compile
	$(ARDUINO_CLI) upload --fqbn $(BOARD) --programmer usbasp $(SKETCH)

clean:
	rm -rf $(BUILD_DIR)

verify:
	$(ARDUINO_CLI) verify --fqbn $(BOARD) $(SKETCH)
