#include<FirebaseArduino.h>
#include<ESP8266WiFi.h>

#define FIREBASE_HOST "<FB_link>"
#define FIREBASE_AUTH "<FB_key>"

#define WIFI_SSID "<WifiNetwork_name>"
#define WIFI_PWD "<Wifi_pwd>"

byte dayCount = 0;

String path = "Temperature/";
String week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

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
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (dayCount < 7)
  {
    Firebase.setFloat(path + week[dayCount], (float)random(20, 35) + random(0, 100)/100.00);
    dayCount++;
    delay(2000);
  }
}
