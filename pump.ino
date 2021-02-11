#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define Pump D5

char auth[] = "API KEY";   
char ssid[] = "3BB_LANGMARINS_2.4GHz"; 
char pass[] = "Josephch56n";     

WidgetLCD lcd1(V0);
WidgetLED LED(V1);

void setup()
{
  Serial.begin(9600);
  pinMode(Pump,OUTPUT); 
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V2){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
      lcd1.clear(); 
      lcd1.print(3,1,"Pump On"); 
      digitalWrite(Pump, HIGH); 
      LED.on();
    } else {
      lcd1.clear(); 
      lcd1.print(3,1,"Pump Off"); 
        digitalWrite(Pump, LOW); 
        LED.off();
    }
}
