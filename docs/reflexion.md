# Was ich anders machen würde

## Grenzwerte gehen beim Neustart verloren

Aktuell werden geänderte Grenzwerte nur im Arbeitsspeicher gehalten. Nach
einem Neustart stehen wieder die Standardwerte im Code. Mit dem internen
EEPROM des Arduino ließen sich die eingestellten Grenzwerte dauerhaft
speichern.

## Sound-Sensor nur relativ kalibriert

Der Sound-Sensor liefert keinen absoluten Lautstärkewert, sondern nur eine
Abweichung von einem Ruhewert. Für zuverlässigere Ergebnisse wäre ein
Sensor mit kalibriertem Ausgang oder eine aufwendigere Signalauswertung
sinnvoll.

## Keine strukturierte Aufteilung des Codes

Der gesamte Code liegt aktuell in einer einzigen Datei. Bei einem größeren
Projekt würde ich Sensorauswertung, Menüsteuerung und Anzeige in separate
Dateien bzw. Funktionen aufteilen, um den Code übersichtlicher zu halten.

## Taster ohne Zwischenspeicherung schneller Eingaben

Mehrere schnelle Tastendrücke direkt nacheinander werden nicht immer
zuverlässig erkannt. Eine interruptbasierte Tastenabfrage wäre hier
robuster als die aktuelle Abfrage in der Hauptschleife.