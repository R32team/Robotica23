#include <WiFi.h>
#include <SparkFun_TB6612.h>

char ssid[] = "STIMATE_ROUTER";       //  your network SSID (name)
char pass[] = "123456ff";             // your network password
int status  = WL_IDLE_STATUS;         // the Wifi radio's status

#define HOST "192.168.0.100"
#define PORT 5050
int connected;
String data;
WiFiClient client;

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
const int offsetA =  1;
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
}

int velocity = 200;  // max-velocity: 255

void loop() {
  
  if (connected == 0) {
    if (client.connect(HOST, PORT)) {
      Serial.println("# Connected to server #");
      Serial.print("IP: ");
      Serial.print(HOST);
      Serial.print(", PORT: ");
      Serial.println(PORT);
  
      connected = 1;
    }
  } 
  else {
    data = String(receiveData());
    
    if (data == "app_1_arduino"){       // ANDATA
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(2000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_1_nao");
    }
    else if (data == "app_2_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(4000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_2_nao");
    }
    else if (data == "app_3_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(6000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_3_nao");
    }
    else if (data == "app_4_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(8000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_4_nao");
    }
    else if (data == "app_5_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(10000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_5_nao");
    }
    else if (data == "app_6_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(12000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_6_nao");
    }
    else if (data == "app_7_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(14000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_7_nao");
    }
    else if (data == "app_8_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(16000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_8_nao");
    }
    /*
    else if (data == "app_9_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(18000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_9_nao");
    }
    else if (data == "app_10_arduino"){
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      forward(motor1, motor2, velocity);   
      delay(20000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_10_nao");
    }
    */
    else if (data == "nao_1_arduino"){  // RITORNO
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(2000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_1_app");
    }
    else if (data == "nao_2_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(4000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_2_app");
    }
    else if (data == "nao_3_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(6000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_3_app");
    }
    else if (data == "nao_4_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(8000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_4_app");
    }
    else if (data == "nao_5_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(10000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_5_app");
    }
    else if (data == "nao_6_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(12000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_6_app");
    }
    else if (data == "nao_7_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(14000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_7_app");
    }
    else if (data == "nao_8_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(16000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_8_app");
    }
    /*
    else if (data == "nao_9_arduino"){  
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(18000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_9_app");
    }
    else if (data == "nao_10_arduino"){ 
      Serial.println("Start - NaoCar");
      pinMode(STBY, OUTPUT);
      back(motor1, motor2, velocity);   
      delay(20000);
      brake(motor1, motor2);
      pinMode(STBY, INPUT);
      Serial.println("End - NaoCar");
      sendData("arduino_10_app");
    }
    */
    
    if (client.connected()) {
      String promptString = Serial.readString();
      if (promptString != "") {
        sendData(promptString);
      }
    } 
    else {
      Serial.println("No server available disconnecting");
      client.stop();
      connected = 0;
    }
  }
  delay(50);
}

void sendData(String data) {
  client.println(data);
  Serial.print("Sent data: ");
  Serial.println(data); 
}

String receiveData() {
  if (client.available()) {
    String dataFromServer = client.readStringUntil('\r');
    Serial.print("Received data: ");
    Serial.println(dataFromServer);
    return dataFromServer;
  }
  return "";
}
