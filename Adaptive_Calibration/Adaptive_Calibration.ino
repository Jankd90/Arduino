#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <afstandssensor.h>
                                        // AfstandsSensor(triggerPin, echoPin);
AfstandsSensor s1(2, 5); 
AfstandsSensor s2(22, 23); 
AfstandsSensor s3(18, 19); 
int len = 10;
int aL[] = {0,0,0,0,0,0,0,0,0,0};
int bL[] = {0,0,0,0,0,0,0,0,0,0};
int cL[] = {0,0,0,0,0,0,0,0,0,0};
int a = 0;
int b = 0;
int c = 0;
const char* ssid     = "AndroidAPE7EC";
const char* password = "snun4082";
AsyncWebServer server(80);
void setup()
{
    Serial.begin(115200);
    pinMode(21, OUTPUT);      // set the LED pin mode

    delay(10);
if(!SPIFFS.begin()){
  Serial.println("An Error has occurred while mounting SPIFFS");
  return;
}
    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  
  server.on("/t", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });

  
  server.on("/s1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(s1.afstandCM()).c_str());
  });

    server.on("/s2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(s2.afstandCM()).c_str());
  });
    
       server.on("/s3", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(s3.afstandCM()).c_str());
  });
    server.begin();



}


void loop(){

  //int adA = s1.afstandCM();
  //int adB = s2.afstandCM();
  //int adC = s3.afstandCM();
  //int aL[] = {aL[1],aL[2],aL[3],aL[4],adA};
  //int bL[] = {bL[1],bL[2],bL[3],bL[4],adB};
  //int cL[] = {cL[1],cL[2],cL[3],cL[4],adC};
  
  //a = (aL[0] + aL[1] + aL[2] + aL[3] + aL[4])/len;
  //b = (bL[0] + bL[1] + bL[2] + bL[3] + bL[4])/len;
  //c = (cL[0] + cL[1] + cL[2] + cL[3] + cL[4])/len;


}
 
