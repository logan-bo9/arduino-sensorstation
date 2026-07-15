# Systemaufbau

Das System besteht aus einem Arduino UNO R4 WiFi, mehreren Sensoren, einem
LCD-Display, drei LEDs und vier Tastern. Die Sensoren liefern Messwerte, die
mit einstellbaren Grenzwerten verglichen werden. Das Ergebnis wird über das
Display und die LEDs angezeigt.

## Ablauf

```text
Sensoren (DHT11, LDR, Sound-Sensor)
        │
        ▼
   Arduino UNO R4 WiFi
        │
        ├──► LCD-Display (Anzeige)
        │
        └──► LEDs (Statusanzeige)
```

## Sensoren im Überblick

- **DHT11:** liefert Temperatur und Luftfeuchtigkeit
- **LDR:** liefert einen Helligkeitswert über einen Spannungsteiler
- **KY-038 Sound-Sensor:** liefert einen analogen Wert, der mit einem beim
  Start gemessenen Ruhewert verglichen wird

## Auswertung

Jeder Sensorwert wird mit einem Grenzwert verglichen. Überschreitet oder
unterschreitet ein Wert seinen Grenzwert, zählt das System eine Warnung.
Die Anzahl der Warnungen bestimmt, welche LED aktiv ist.
