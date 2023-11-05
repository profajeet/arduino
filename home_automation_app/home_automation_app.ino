#include <ESP8266WiFi.h>
#define s1 D1  // LED at GPIO4 D2
#define s2 D2 
#define s3 D3
#define s4 D4
#define s5 D5
#define s6 D6
#define s7 D7
#define s8 D8
  
const char* ssid = "Extreme1";
const char* password = "data kam hair";
unsigned char status_led=0;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  pinMode(s1, OUTPUT);
  digitalWrite(s1, LOW);
  pinMode(s2, OUTPUT);
  digitalWrite(s2, LOW);
  pinMode(s3, OUTPUT);
  digitalWrite(s3, LOW);
  pinMode(s4, OUTPUT);
  digitalWrite(s4, LOW);
  pinMode(s5, OUTPUT);
  digitalWrite(s5, LOW);
  pinMode(s6, OUTPUT);
  digitalWrite(s6, LOW);
  pinMode(s7, OUTPUT);
  digitalWrite(s7, LOW);
  pinMode(s8, OUTPUT);
  digitalWrite(s8, LOW);
 
  // Connect to WiFi network
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
  Serial.println("Server started at...");
  Serial.println(WiFi.localIP());
 
}
 
void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while (! client.available())
  {
    delay (1);
  }
  
 
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
 
  // Match the request
  
  if (req.indexOf("/s1off") != -1)  {
    status_led=0;
    digitalWrite(s1, LOW);
    Serial.println("s1 OFF");
  }
  else if(req.indexOf("/s1on") != -1)
  {
    status_led=1;
    digitalWrite(s1,HIGH);
    Serial.println("s1 ON");
  }
  else if (req.indexOf("/s2off") != -1)  {
    status_led=0;
    digitalWrite(s2, LOW);
    Serial.println("s2 OFF");
  }
  else if(req.indexOf("/s2on") != -1)
  {
    status_led=1;
    digitalWrite(s2,HIGH);
    Serial.println("s2 ON");
  }
   else if (req.indexOf("/s3off") != -1)  {
    status_led=0;
    digitalWrite(s3, LOW);
    Serial.println("s3 OFF");
  }
  else if(req.indexOf("/s3on") != -1)
  {
    status_led=1;
    digitalWrite(s3,HIGH);
    Serial.println("s3 ON");
  }
   else if (req.indexOf("/s4off") != -1)  {
    status_led=0;
    digitalWrite(s4, LOW);
    Serial.println("s4 OFF");
  }
  else if(req.indexOf("/s4on") != -1)
  {
    status_led=1;
    digitalWrite(s4,HIGH);
    Serial.println("s4 ON");
  }
   else if (req.indexOf("/s5off") != -1)  {
    status_led=0;
    digitalWrite(s5, LOW);
    Serial.println("s5 OFF");
  }
  else if(req.indexOf("/s5on") != -1)
  {
    status_led=1;
    digitalWrite(s5,HIGH);
    Serial.println("s5 ON");
  }
   else if (req.indexOf("/s6off") != -1)  {
    status_led=0;
    digitalWrite(s6, LOW);
    Serial.println("s6 OFF");
  }
  else if(req.indexOf("/s6on") != -1)
  {
    status_led=1;
    digitalWrite(s6,HIGH);
    Serial.println("s6 ON");
  }
   else if (req.indexOf("/s7off") != -1)  {
    status_led=0;
    digitalWrite(s7, LOW);
    Serial.println("s7 OFF");
  }
  else if(req.indexOf("/s7on") != -1)
  {
    status_led=1;
    digitalWrite(s7,HIGH);
    Serial.println("s7 ON");
  }
   else if (req.indexOf("/s8off") != -1)  {
    status_led=0;
    digitalWrite(s8, LOW);
    Serial.println("s8 OFF");
  }
  else if(req.indexOf("/s8on") != -1)
  {
    status_led=1;
    digitalWrite(s8,HIGH);
    Serial.println("s8 ON");
  }
 
// Return the response
/*client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println(""); 

client.println("<!DOCTYPE HTML>");
client.println("<HTML>");
client.println("<H1> LED CONTROL </H1>");
client.println("<br />");
 
 client.println("<a href=\"/ledon\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
 client.println("<a href=\"/ledoff\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");
 client.println("</html>"); */
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
