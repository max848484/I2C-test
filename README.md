# Test I2C pour ESP32-C3

Ce programme a été développé pour **tester la communication avec un périphérique I²C** à partir d'une carte ESP32-C3 DevKitM-1. Il permet de vérifier si un capteur ou un module connecté répond correctement à l'adresse I²C spécifiée.

## Matériel requis

- ESP32-C3 DevKitM-1
- Module ou capteur I²C à tester
- Câblage correct pour SDA et SCL
- Pull-ups sur les lignes I²C si le module ne les possède pas déjà

## Fonctionnalités

- Initialise le bus I²C sur les broches spécifiées
- Scanne l'adresse I²C fournie pour détecter la présence du périphérique
- Affiche un message clair dans le moniteur série selon que le périphérique répond ou non
- Compatible avec la librairie `Wire` d'Arduino

## Utilisation

1. Connecter le périphérique I²C à la carte ESP32-C3 avec SDA et SCL correctement reliés.
2. Modifier dans le code les broches SDA et SCL si nécessaire.
3. Définir l'adresse I²C à tester.
4. Téléverser le programme sur l’ESP32-C3.
5. Ouvrir le **Moniteur Série** (115200 bauds) pour observer le résultat.

## Compatibilité

Testé avec succès sur :  
- ESP32-C3 DevKitM-1  

## Licence

Ce projet est libre et peut être utilisé à des fins personnelles ou éducatives.
