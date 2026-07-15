# Herausforderungen

## Sound-Sensor liefert keinen absoluten Wert

Der KY-038 gibt keinen kalibrierten Lautstärkewert aus. Der Rohwert wird
zusätzlich durch Versorgungsspannung und Umgebungsbedingungen beeinflusst.

**Lösung:** Beim Start wird ein Ruhewert (Baseline) gemessen. Danach wird
nur noch die Abweichung vom Ruhewert ausgewertet, nicht der Rohwert selbst.

## Taster reagieren mehrfach

Mechanische Taster erzeugen beim Drücken kurze Signalschwankungen
(Prellen), die ohne Behandlung zu mehrfachen Eingaben führen.

**Lösung:** Nach jedem erkannten Tastendruck wird kurz gewartet
(Software-Entprellung), bevor der nächste Tastendruck erkannt wird.

## DHT11 liefert fehlerhafte Werte

Beim ersten Testaufbau lieferte der DHT11 zeitweise ungültige Werte.

**Lösung:** Verkabelung und Bibliothek überprüft und den Sensor einzeln
getestet, bis die Werte zuverlässig ausgelesen wurden.
