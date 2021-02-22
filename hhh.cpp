#include <ESP8266WiFi.h>

// needed for lobrary
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#define SW_PIN 0

void setup() {
    Serial.begin(115200);
    pinMode(SW_PIN, INPUT_PULLUP);

    // WiFiManager
    // Local intialization
    WiFiManager wifiManager;

    Serial.println("Reset wifi config?: ");
    for(int i=5; i>0; i--){
        Serial.print(String(i)+ " ");
        delay(1000);
    }


    // Reset saved settings
    if(digitalRead(SW_PIN) == LOW) // Press button
    {
        Serial.println();
        Serial.println("Reset wifi config");
        wifiManager.resetSettings();
        // wifiManager.setAPStaticIPConfig(_ip, _gw, _sn);
    }

    wifiManager.autoConnect("AutoConnecAP");

    Serial.println("connected...OK");
}

void loop(){
    
}  