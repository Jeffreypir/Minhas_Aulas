
/*==================== PROGRAM ==============================
 * Program: sensorUltrassonico.ino
 * Date of Create: 2025-05-20 13:31:13
 * Update in: 2025-05-20 15:49:31
 * Author:Jefferson Bezerra dos Santos
 * Description: Sensor Ultrassonico
 *===========================================================
 */

#include <Arduino.h>
#include <Servo.h>

Servo myservo;

/* ==================== MACROS ============================ */

// Definindo os pinos do ultrassonico 
#define TRIGPIN 9
#define ECHOPIN 10
#define LEDPIN 13

// Definindo pino do Servo 
#define SERVPIN 8

/* ================== End of macro =========================*/

long duration;
int distance; 


/* ================ PROTOTYPE OF FUNCTIONS ================ */

/* ================== End of prototype =====================*/


/*=================== FUNCTION SETUP () ======================
 * Function: setup()
 * Description: Put setup configuration 
 * ==========================================================
 */
void setup() {

  myservo.attach(SERVPIN);

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);


  Serial.begin(9600); // Inicia a comunicação serial para monitoramento
}
/*----------End of function-----------------*/



/*=================== FUNCTION SETUP () ======================
 * Function: loop()
 * Description: Put code for loop
 * ==========================================================
 */
void loop() {
  // Limpa o trigPin 
  digitalWrite(TRIGPIN, LOW);
  delay(2);

  // Define o trigPin como HIGH por 10 microssegundos 
  digitalWrite(TRIGPIN, HIGH);
  delay(10);
  digitalWrite(TRIGPIN, LOW);

  // Le o echoPin,  retorna o tempo de viagme da onda em microsegundos
  duration = pulseIn(ECHOPIN, HIGH);

  // Calcular a distancia 
  distance = duration * 0.017; 

  if (distance < 10) {
    digitalWrite(LEDPIN, HIGH);
    myservo.write(0);
  } else {
    digitalWrite(LEDPIN, LOW);
    myservo.write(90);
  }

  // Mostra a distancia no monitor serial 
  Serial.print("Dist: ");
  Serial.print(distance);
  Serial.print("cm  ");

  delay (50);

}
/*----------End of function-----------------*/


