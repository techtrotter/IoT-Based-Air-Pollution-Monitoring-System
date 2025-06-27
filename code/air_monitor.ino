/* IoT Air Pollution Monitoring System
 * Author: Bijoy Laxmi Biswas
 */

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

WiFiClient client;

unsigned long myChannelNumber = 123456;
const char * myWriteAPIKey = "YOUR_API_KEY";

const int mq135Pin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  ThingSpeak.begin(client);
}

void loop() {
  int gasValue = analogRead(mq135Pin);
  ThingSpeak.writeField(myChannelNumber, 1, gasValue, myWriteAPIKey);
  delay(20000);
}
