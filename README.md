# Arduino-Sensorstation

Arduino-Projekt zur Integration mehrerer Sensoren mit LCD-Anzeige,
Menüsteuerung und einer LED-basierten Statusanzeige.

## Funktionen

- Messung von Temperatur und Luftfeuchtigkeit (DHT11)
- Messung der Helligkeit (LDR)
- Erkennung von Geräuschänderungen (KY-038)
- Anzeige aller Werte über ein LCD-Display
- Menüsteuerung über vier Taster
- Einstellbare Grenzwerte je Sensor
- Statusanzeige über drei LEDs (grün, orange, rot)

## Hardware

Details zu Bauteilen und Verkabelung:

- [Stückliste](hardware/stueckliste.md)
- [Pinbelegung](hardware/pinbelegung.md)

## Software

Der Arduino-Code liegt in [`src/arduino_sensorstation.ino`](src/arduino_sensorstation.ino).

## Dokumentation

- [Projektziel](docs/projektziel.md)
- [Systemaufbau](docs/systemaufbau.md)
- [Menü und Bedienung](docs/menue-und-bedienung.md)
- [Warnlogik](docs/warnlogik.md)
- [Entwicklung](docs/entwicklung.md)
- [Herausforderungen](docs/herausforderungen.md)
- [Gehäuse](docs/gehaeuse.md)

## Bilder

Bilder zum Aufbau, zum Menü und zum Gehäuse befinden sich im Ordner
[`bilder/`](bilder/).
