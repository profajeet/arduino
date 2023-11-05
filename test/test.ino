// # define led 13
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    Serial.println("LED_BUILTIN on")
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    Serial.println("LED_BUILTIN off")
}