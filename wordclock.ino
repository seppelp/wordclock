//WLAN
#include <ESP8266WiFi.h>

//NTP
#include <NTPClient.h>
#include <WiFiUdp.h>

//Zeitzone
#include <Time.h>
#include <TimeLib.h>
#include <Timezone.h>

//FastLED
#include <FastLED.h>

//Wortuhr
#include <wortuhr.h>

//Hier anzahl der LEDS und Pins festlegen
#define NUM_LEDS 30
#define CLOCK_PIN 5
#define DATA_PIN 4
CRGB leds[NUM_LEDS]; //LED-Array anlegen


const char* ssid     = "NetzOG"; // Your ssid
const char* password = "PrinzenIn35606Solms!"; // Your Password


WiFiServer server(80);
WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0, 60000);


//Timezone
//Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = { "CEST", Last, Sun, Mar, 2, 120 };     //Central European Summer Time
TimeChangeRule CET = { "CET ", Last, Sun, Oct, 3, 60 };       //Central European Standard Time
Timezone CE(CEST, CET);
TimeChangeRule *tcr;        //pointer to the time change rule, use to get the TZ abbrev
time_t utc, local;



void setup() {
Serial.begin(115200);
delay(10);
Serial.println();

// Connect to WiFi network
WiFi.mode(WIFI_STA);
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
Serial.println("WiFi connected");

// Start the server
server.begin();
Serial.println("Server started");

// Print the IP address
Serial.println(WiFi.localIP());

// Zeit Client Starten
  timeClient.begin();

//LED initialisieren
FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS); 
  
}

void loop() {
  //Zeit Update
timeClient.update();
time_t t = getTime();

/*
  //Web-Ausgabe
WiFiClient client = server.available();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");  // the connection will be closed after completion of the response
client.println("Refresh: 5");  // refresh the page automatically every 5 sec
client.println();
client.println("<!DOCTYPE html>");
client.println("<html xmlns='http://www.w3.org/1999/xhtml'>");
client.println("<head>\n<meta charset='UTF-8'>");
client.println("<title>ESP8266 Time</title>");
client.println("</head>\n<body>");

client.print("Zeit (UTC von NTP) " + timeClient.getFormattedTime());
client.print("<br> Korrigierte Stunde ");
client.println(hour(t));
client.println("<br>");
for ( unsigned int ii=0; ii< de_zwanzig.size(); ii++){
  client.println(de_zwanzig[ii]);
  client.println("<br>");
}
client.print("</body>\n</html>");
*/
seth(t);
setm(t);
setmp(t);

/*
  //LED schalten
leds[0] = CRGB::White;
FastLED.show();
leds[0] = CRGB::Black;
*/
delay(5000); //delay for reread
}


time_t getTime(){
  //Zeitzonen Umrechnung
setTime(timeClient.getEpochTime());
time_t tt = now();
time_t t = CE.toLocal(tt);
  return t;
}

void sprich(std::vector<int> &v){
  for(int i = 0; i<v.size();i++){
    Serial.println(v[i]);
  }
}

//Stundenwörter einschalten
void seth(time_t t){
  int h = hour(t);
  int m = minute(t);

  if (h>12){
    h=h-12;
  }
  
  if (h == 1 && m <5){
    setLED(de_h_ein);
    setLED(de_uhr);
  }
  else if (m >= 25){
    setLED(de_h[h]);
  }
  else if (m < 5){
    setLED(de_h[h-1]);
    setLED(de_uhr);
  }
  else if (m < 25){
    setLED(de_h[h-1]);
  }
}

//Minutenwörter einschalten

void setm(time_t t){
  int m = minute(t);
    if (m<5){ 
      Serial.println(".");
    } 
    else if (m>=55 || m<10){
      setLED(de_fuenf);
    }
    else if (m>=50 || m<15){
      setLED(de_zehn);
    }
    else if (m>= 45 || m<20){
      setLED(de_viertel);
    }
    else if (m>=40 || m<25){
      setLED(de_zwanzig);
    }
    else {
      setLED(de_halb);
    }


    if (m>=40 || m>=25 && m<=29) {
      setLED(de_vor);
    }
    else if (m>=5 && m<=20 || m<40 && m>=35){
      setLED(de_nach);
    }
}

//Minutenpunkte schalten
void setmp(time_t t){
  int p = minute(t)%5;
    for(int i = 0; i<p;i++){
      leds[de_mp[i]] = CRGB::White;
      Serial.println(de_mp[i]);
    }  
}
void setei(){
  setLED(de_esist);
}


//Alle LEDS ausschalten
void clearLED(){
  for(int i = 0; i<=113;i++){
    leds[i] = CRGB::Black;
  }
}


//LED des wortes x aktivieren
void setLED(std::vector<int> &v){
    for(int i = 0; i<v.size();i++){
      leds[v[i]] = CRGB::White;
      Serial.println(v[i]);
    }
}



