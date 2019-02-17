#include<FirebaseArduino.h>
#include<ESP8266WiFi.h>

#define FIREBASE_HOST "<FB_link>"
#define FIREBASE_AUTH "<FB_key>"

#define WIFI_SSID "<WifiNetwork_name>"
#define WIFI_PWD "<Wifi_pwd>"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setFloat("Float", 2.5);
}

void loop()
{
  // put your main code here, to run repeatedly:
    float val = Firebase.getFloat("Float");
    Serial.println(val);
    Firebase.setFloat("Float", val + 1.0);
    delay(2000);
}
