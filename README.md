# Arduino Sensorstation

Arduino-Projekt zur Integration mehrerer Sensoren mit LCD-Anzeige,
Menüsteuerung und einer LED-basierten Statusanzeige.
Hier gehts zum [Fertiges Produkt](bilder/02-gesamtaufbau/04-produkt.png) <--

## [Projektziel](docs/projektziel.md)

Ziel war nicht der Bau eines fertigen Systems, sondern das Verständnis
einzelner Sensoren: Anschluss, Messwerte und Grenzen. Die Sensorstation
selbst ist dabei eher ein Nebenprodukt als das eigentliche Ziel.

## Arbeit mit den Sensoren

Jeder Sensor wurde einzeln aufgebaut und getestet, bevor er ins
Gesamtsystem übernommen wurde.

### Temperatur und Luftfeuchtigkeit (DHT11)

[DHT11 Test](bilder/01-einzeltests/06-dht11-test.jpg)

Verkabelung und erste Messwerte auf dem Breadboard.

### Helligkeit (LDR)

[LDR Test](bilder/01-einzeltests/08-ldr-testdata.jpg)

Kalibrierung anhand eigener Messreihen bei unterschiedlichem Licht.

### Lautstärke (Sound-Sensor)

[Sound Test](bilder/01-einzeltests/09-sound-test1.jpg)

Der Sensor liefert nur eine Abweichung vom Ruhepegel, keinen absoluten
Wert. Das zeigte sich erst bei den Tests.

## Gehäuse

[3D-Modell (Tinkercad)](bilder/05-gehaeuse/gehaeuse-3d-proto.png)

[Fertiges Gehäuse](bilder/05-gehaeuse/02-endergebnis.jpg)

Das Gehäuse wurde zunächst als 3D-Modell entworfen und anschließend
gefertigt.

## Aufbau und Bedienung

[Gesamtaufbau](bilder/02-gesamtaufbau/03-verkabelung-final.jpg)

[Menü](bilder/03-menue/02-startbildschirm.jpg)

Ein Tasten-Menü zeigt Messwerte an und erlaubt das Ändern von
Grenzwerten. Dazu kommt eine dreistufige Statusanzeige (OK, Warnung,
Alarm).

[weitere Bilder](bilder)

## Hardware

- [Stückliste](hardware/stueckliste.md)
- [Pinbelegung](hardware/pinbelegung.md)

## Software

- [Quellcode](src/arduino_sensorstation.ino)

## Was ich dabei gelernt habe

- Analoge und digitale Sensoren unterscheiden sich in Ansteuerung und Rauschen
- Kalibrierung war bei einfachen Sensoren oft wichtiger als der reine Anschluss
- Schwankende Werte, etwa beim Sound-Sensor, ließen sich nur durch Testen einordnen
- Ein einfaches Menü reichte aus, um die Sensordaten nutzbar zu machen

## Weitere Dokumentation

- [Systemaufbau](docs/systemaufbau.md)
- [Menü und Bedienung](docs/menue-und-bedienung.md)
- [Warnlogik](docs/warnlogik.md)
- [Entwicklung](docs/entwicklung.md)
- [Herausforderungen](docs/herausforderungen.md)
- [Was ich anders machen würde](docs/reflexion.md)
