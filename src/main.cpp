/********************************************************************
 * Fichier : main.cpp
 * Auteur  : M. Champagne
 * Date    : 2025-08-13
 * Description :
 *   Programme de test pour valider la communication avec un 
 *   périphérique I2C.
 *   - Test de l'initialisation I2C
 *   - Vérification de la présence de l'esclave à l'adresse spécifiée
 *   - Clignotement de la LED intégrée
 ********************************************************************/

#include <Arduino.h>
#include <Wire.h>

static const uint8_t SDA_PIN = 7;
static const uint8_t SCL_PIN = 6;
static const uint8_t ESCLAVE_ADDR = 0x57; //adresse 0b1010111
static const uint32_t I2C_FREQ = 100000;

// ====================== SETUP ===========================
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
  else {
    Serial.println("❌ Aucun périphérique ne répond à cette adresse.");
  }
}

// ====================== LOOP ============================
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
