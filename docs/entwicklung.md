# Entwicklung

## Einzeltests

Jede Komponente wurde zuerst einzeln angeschlossen und getestet, bevor sie
Teil des Gesamtsystems wurde:

- LCD1602 über I2C
- DHT11 (Temperatur, Luftfeuchtigkeit)
- LDR (Helligkeit)
- KY-038 Sound-Sensor
- Taster
- LEDs

## Integration

Nach den Einzeltests wurden alle Komponenten zu einem Gesamtsystem
zusammengeführt:

- Menüsystem mit den vier Tastern
- Auswertung aller Sensorwerte
- Verwaltung einstellbarer Grenzwerte
- Statusanzeige über LEDs

## Ergebnis

Der aktuelle Stand ist ein vollständig funktionierender Prototyp auf
Breadboard-Basis mit Bedienung über Taster und LCD-Anzeige.
