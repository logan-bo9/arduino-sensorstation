# Warnlogik

Jeder Sensorwert wird mit einem Grenzwert verglichen. Bei jeder
Grenzwertverletzung wird ein Zähler um eins erhöht. Die Anzahl der
Warnungen bestimmt den Status der Station.

## Bedingungen

| Sensor | Warnung, wenn ... |
|---|---|
| Temperatur | Wert größer als der Grenzwert |
| Luftfeuchtigkeit | Wert größer als der Grenzwert |
| Helligkeit | Wert kleiner als der Grenzwert |
| Geräusch | wenn die Abweichung = größer als der Grenzwert |

## Statusanzeige

| Warnungen | LED | Bedeutung |
|---|---|---|
| 0 | Grün | Kein Grenzwert verletzt |
| 1 | Orange | Eine Grenzwertverletzung |
| 2 oder mehr | Rot | Mehrere Grenzwertverletzungen |
