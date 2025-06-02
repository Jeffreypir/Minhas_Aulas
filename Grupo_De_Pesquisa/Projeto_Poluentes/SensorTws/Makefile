
BOARD=arduino:avr:uno
PORT=COM10
SKETCH=SensorTws.ino
BUILD_DIR=build

compile:
	arduino-cli compile --fqbn $(BOARD) $(SKETCH)

upload:
	arduino-cli upload -p $(PORT) --fqbn $(BOARD) $(SKETCH)

generate_commands:
	arduino-cli compile --fqbn $(BOARD) --build-path $(BUILD_DIR) $(SKETCH)
	powershell -Command "Copy-Item -Path '$(BUILD_DIR)\compile_commands.json' -Destination '.'"
