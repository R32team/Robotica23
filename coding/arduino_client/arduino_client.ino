#include <ESP8266WiFi.h>

#define HOST "192.168.0.150"
#define PORT 5050

#define SSID ""
#define PASSWORD ""

WiFiClient client;
int connected;

void setup() {
  Serial.begin(115200);

  while (Serial.available() == 0) {}

  Serial.print("# Connecting to WiFi #");
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("# WiFi connected#");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  delay(500);
}


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
  } else {
    receiveData();

    if (client.connected()) {
      String promptString = Serial.readString();
      if (promptString != "") {
        sendData(promptString);
      }
    } else {
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
