// Questa è la libreria per TB6612 che contiene la classe Motor e tutte
// le funzioni
#include <SparkFun_TB6612.h>
#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

void setup()
{
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){5, 6, 7, 8, 9, 10}, SensorCount);
  for (int i = 0; i < 250; i ++){
    qtr.calibrate();
    delay(20);
  }
  Serial.begin(9600);
}

// Pin per tutti gli input

#define PWMA 5
#define AIN2 4
#define AIN1 6
#define STBY 7
#define BIN1 8
#define BIN2 9
#define PWMB 10
// queste costanti vengono utilizzate per consentire di configurare i
// motori e allinea con nomi di funzioni come forward.
// Il valore può essere 1 o -1
const int offsetA = 1;
const int offsetB = -1;

// Inizializzazione dei motori.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);



void loop()
{qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  delay(250);
  
  //Motori avanti
  forward(motor1, motor2, 100);
  delay(1000);
  /*
  // Gira a sinistra
  right(motor1, motor2, 100);
  delay(1000);

  //Motori avanti
  forward(motor1, motor2, 100);
  delay(1000);

  // Gira a destra
  left(motor1, motor2, 100);
  delay(1000);

  //Motori indietro
  back(motor1, motor2, -100);
  delay(1000);

  // Gira a sinistra
  right(motor1, motor2, 100);
  delay(1000);

  //Motori indietro
  back(motor1, motor2, -100);
  delay(1000);
  */
}
