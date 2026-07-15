# Pinbelegung

| Komponente | Pin |
|---|---|
| Sound-Sensor (AO) | A0 |
| LDR | A3 |
| DHT11 | D5 |
| Taster BACK | D3 |
| Taster OK | D4 |
| Taster DOWN | D6 |
| Taster UP | D7 |
| LED grün | D9 |
| LED orange | D10 |
| LED rot | D11 |
| LCD (I2C) | A4 (SDA), A5 (SCL) |

Alle Taster nutzen den internen Pull-Up-Widerstand (`INPUT_PULLUP`).
Der LDR ist als Spannungsteiler mit einem zusätzlichen Widerstand aufgebaut.
