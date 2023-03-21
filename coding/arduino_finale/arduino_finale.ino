#include <WiFi.h>
#include <SparkFun_TB6612.h>

char ssid[] = "STIMATE_ROUTER";       //  your network SSID (name)
char pass[] = "123456ff";             // your network password
int status  = WL_IDLE_STATUS;         // the Wifi radio's status

// Pin per tutti gli input
#define PWMA 5
#define AIN2 4
#define AIN1 6
#define STBY 7 // Non collegabile
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


void setup() {
  // initialize serial:
  Serial.begin(9600);

  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if (status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while(true);
  }
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
    Serial.println(WiFi.localIP());
  }

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
}

void loop() {
  //Motori avanti
  forward(motor1, motor2, 100);
  delay(1000);
  
}
