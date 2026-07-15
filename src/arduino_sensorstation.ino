#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- BUTTONS ----------------
const int upBtn = 7;
const int downBtn = 6;
const int okBtn = 4;
const int backBtn = 3;

// ---------------- SENSOR SETUP ----------------
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int ldrPin = A3;
const int soundPin = A0;

// ---------------- STATES ----------------
enum Mode { HOME, VIEW, EDIT };
Mode mode = HOME;

enum Sensor { TEMP, HUM, LIGHT, SOUND };
Sensor sensorIndex = TEMP;

// ---------------- VALUES ----------------
float temp;
float hum;
int light;
int sound;

// ---------------- LIMITS ----------------
float tempLimit = 30;
float humLimit = 70;
int lightLimit = 200;
int soundLimit = 30;

// ---------------- BUTTON MEMORY ----------------
bool lastUp = HIGH;
bool lastDown = HIGH;
bool lastOk = HIGH;
bool lastBack = HIGH;

// ---------------- LEDS ----------------
const int greenLED = 9;
const int orangeLED = 10;
const int redLED = 11;

// ---------------- SOUND ----------------
float soundBaseline = 0;
int soundDiff = 0;
int soundRaw = 0;

// ---------------- STATUS ----------------
int warnings = 0;

// ---------------- BUTTON FUNCTION (mit Entprellung) ----------------
bool pressed(int pin, bool &lastState) {
  bool current = digitalRead(pin);

  if (lastState == HIGH && current == LOW) {
    delay(25); // Entprellung
    lastState = current;
    return true;
  }

  lastState = current;
  return false;
}

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(upBtn, INPUT_PULLUP);
  pinMode(downBtn, INPUT_PULLUP);
  pinMode(okBtn, INPUT_PULLUP);
  pinMode(backBtn, INPUT_PULLUP);

  dht.begin();

  pinMode(greenLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Sound-Baseline beim Start messen
  long sum = 0;

  for (int i = 0; i < 200; i++) {
    analogRead(soundPin); // erste Messung verwerfen
    sum += analogRead(soundPin);
    delay(5);
  }

  soundBaseline = sum / 200.0;
}

// ---------------- LOOP ----------------
void loop() {

  // -------- SENSOR UPDATE --------
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  light = analogRead(ldrPin);

  // Soundmessung stabilisieren
  analogRead(soundPin);
  soundRaw = analogRead(soundPin);

  soundDiff = abs(soundRaw - soundBaseline);

  // Ruhewert langsam nachführen
  if (soundDiff < 15) {
    soundBaseline = soundBaseline * 0.99 + soundRaw * 0.01;
  }

  warnings = 0;

  if (temp > tempLimit) warnings++;
  if (hum > humLimit) warnings++;
  if (light < lightLimit) warnings++;
  if (soundDiff > soundLimit) warnings++;

  if (warnings == 0) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (warnings == 1) {
    digitalWrite(greenLED, LOW);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  // -------- BUTTON LOGIC --------
  if (mode == HOME) {
    if (pressed(downBtn, lastDown)) {
      mode = VIEW;
    }

    if (pressed(upBtn, lastUp)) {
      mode = VIEW;
      sensorIndex = SOUND;
    }
  }

  if (mode == VIEW) {
    if (pressed(downBtn, lastDown)) {
      sensorIndex = (Sensor)((sensorIndex + 1) % 4);
    }

    if (pressed(upBtn, lastUp)) {
      sensorIndex = (Sensor)((sensorIndex + 3) % 4);
    }

    if (pressed(okBtn, lastOk)) {
      mode = EDIT;
    }

    if (pressed(backBtn, lastBack)) {
      mode = HOME;
    }
  }

  if (mode == EDIT) {
    if (pressed(upBtn, lastUp)) {
      if (sensorIndex == TEMP) tempLimit += 1;
      if (sensorIndex == HUM) humLimit += 1;
      if (sensorIndex == LIGHT) lightLimit += 10;
      if (sensorIndex == SOUND) soundLimit += 10;
    }

    if (pressed(downBtn, lastDown)) {
      if (sensorIndex == TEMP) tempLimit -= 1;
      if (sensorIndex == HUM) humLimit -= 1;
      if (sensorIndex == LIGHT) lightLimit -= 10;
      if (sensorIndex == SOUND) soundLimit -= 10;
    }

    if (pressed(okBtn, lastOk)) {
      mode = VIEW;
    }

    if (pressed(backBtn, lastBack)) {
      mode = VIEW;
    }
  }

  // -------- DISPLAY --------
  lcd.clear();

  if (mode == HOME) {
    lcd.setCursor(0, 0);
    lcd.print("ENV STATION");

    lcd.setCursor(0, 1);

    if (warnings == 0) {
      lcd.print("STATUS: OK");
    }
    else if (warnings == 1) {
      lcd.print("STATUS: WARN");
    }
    else {
      lcd.print("STATUS: ALERT");
    }
  }

  if (mode == VIEW) {
    if (sensorIndex == TEMP) {
      lcd.setCursor(0, 0);
      lcd.print("TEMP: ");
      lcd.print(temp);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("LIM:");
      lcd.print(tempLimit);
    }

    if (sensorIndex == HUM) {
      lcd.setCursor(0, 0);
      lcd.print("HUM: ");
      lcd.print(hum);
      lcd.print("%");

      lcd.setCursor(0, 1);
      lcd.print("LIM:");
      lcd.print(humLimit);
    }

    if (sensorIndex == LIGHT) {
      lcd.setCursor(0, 0);
      lcd.print("LIGHT:");
      lcd.print(light);

      lcd.setCursor(0, 1);
      lcd.print("LIM:");
      lcd.print(lightLimit);
    }

    if (sensorIndex == SOUND) {
      lcd.setCursor(0, 0);
      lcd.print("SOUND:");
      lcd.print(soundDiff);

      lcd.setCursor(0, 1);
      lcd.print("LIM:");
      lcd.print(soundLimit);
    }
  }

  if (mode == EDIT) {
    lcd.setCursor(0, 0);
    lcd.print("EDIT LIMIT");

    lcd.setCursor(0, 1);

    if (sensorIndex == TEMP) {
      lcd.print("T:");
      lcd.print(tempLimit);
    }

    if (sensorIndex == HUM) {
      lcd.print("H:");
      lcd.print(humLimit);
    }

    if (sensorIndex == LIGHT) {
      lcd.print("L:");
      lcd.print(lightLimit);
    }

    if (sensorIndex == SOUND) {
      lcd.print("S:");
      lcd.print(soundLimit);
    }
  }

  delay(100);
}
