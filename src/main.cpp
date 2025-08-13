#include <Arduino.h>
#include <Wire.h>

static const uint8_t SDA_PIN = 7;
static const uint8_t SCL_PIN = 6;
static const uint8_t ESCLAVE_ADDR = 0x57; //adresse 0b1010111
static const uint32_t I2C_FREQ = 100000;

void scanI2C();

//Cette fonction est exécuté automatiquement à la suite d'un reset. 
//Elle n'est plus jamais appelé par la suite.
void setup() {
  //Initialisaion de la broche LED_BUILTIN en sortie
  pinMode(LED_BUILTIN, OUTPUT);

  //Initialisation du port série à 9600bps
  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("\n=== Scanner I2C (ESP32-C3) ===");

  //Initialisation du port I2C
  bool initOK = Wire.begin(SDA_PIN, SCL_PIN, I2C_FREQ);
  if (initOK) {
    Serial.println("✅ Initilisation I2C complété !");
  }
  else{
    Serial.println("❌ Impossible d'initialiser l'I2C !");
    return;
  }

  //Test de communication avec l'esclave I2C
  Wire.beginTransmission(ESCLAVE_ADDR);
  byte error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("✅ Réponse détectée : le périphérique est présent !");
  }
  else if (error == 4) {
    Serial.println("❌ Erreur inconnue lors de la communication !");
  }
  else {
    Serial.println("❌ Aucun périphérique ne répond à cette adresse.");
  }
}

//Cette fonction est exécutée en boucle à l'infini
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
