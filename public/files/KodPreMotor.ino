#include <LiquidCrystal.h>

// --- LCD pripojenie (RS, E, D4, D5, D6, D7) ---
LiquidCrystal lcd(9, 10, 11, 12, 13, A0); // D7 je A0

// --- TB6600 piny ---
#define PUL_PIN 3
#define DIR_PIN 4
#define ENA_PIN 5

// --- Ovládací enkóder ---
#define ENC_CLK 6
#define ENC_DT 7
#define ENC_SW 8

// --- Merací enkóder ---
#define RPM_CLK A1
#define RPM_DT  A2  // nepovinné, len ak chceš smer
#define PULSES_PER_REV 20  // impulzy na otáčku meracieho enkódera

// --- Konštanty ---
#define STEPS_PER_REV 20
#define MEASUREMENT_INTERVAL 1000 // ms

// --- Premenné ---
volatile int speedDelay = 300;   // delay medzi krokmi (µs)
int lastStateCLK;
bool direction = true;
bool motorEnabled = false;
unsigned long buttonPressStart = 0;
bool buttonPressed = false;
const unsigned long longPressTime = 500; // ms

// --- RPM meranie ---
unsigned long lastMeasurement = 0;
float rpmMeasured = 0;
unsigned long pulseCount = 0;
int lastRPMState = LOW;

void setup() {
  // --- Nastavenie pinov ---
  pinMode(PUL_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);

  pinMode(ENC_CLK, INPUT);
  pinMode(ENC_DT, INPUT);
  pinMode(ENC_SW, INPUT_PULLUP);

  pinMode(RPM_CLK, INPUT);
  pinMode(RPM_DT, INPUT);

  digitalWrite(ENA_PIN, HIGH); // TB6600 vypnutý
  digitalWrite(DIR_PIN, direction);

  lastStateCLK = digitalRead(ENC_CLK);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("TB6600 Control");
  delay(1000);
  lcd.clear();
  updateLCD();
}

void loop() {
  // --- Ovládací enkóder (zmena rýchlosti) ---
  int currentStateCLK = digitalRead(ENC_CLK);
  if (currentStateCLK != lastStateCLK && currentStateCLK == HIGH) {
    if (digitalRead(ENC_DT) != currentStateCLK)
      speedDelay -= 5;  // spomalenie
    else
      speedDelay += 5;  // zrýchlenie

    if (speedDelay < 10) speedDelay = 10;
    if (speedDelay > 300) speedDelay = 300;

    updateLCD();
  }
  lastStateCLK = currentStateCLK;

  // --- Tlačidlo enkódera ---
  int btnState = digitalRead(ENC_SW);
  if (btnState == LOW && !buttonPressed) {
    buttonPressed = true;
    buttonPressStart = millis();
  }
  if (btnState == HIGH && buttonPressed) {
    unsigned long pressDuration = millis() - buttonPressStart;
    buttonPressed = false;

    if (pressDuration < longPressTime) {
      // krátke stlačenie → zmena smeru
      direction = !direction;
      digitalWrite(DIR_PIN, direction);
    } else {
      // dlhé stlačenie → zap/vyp
      motorEnabled = !motorEnabled;
      digitalWrite(ENA_PIN, motorEnabled ? LOW : HIGH);
    }
    updateLCD();
  }

  // --- Meranie RPM z meracieho enkódera ---
  int currentRPMState = digitalRead(RPM_CLK);
  if (currentRPMState == HIGH && lastRPMState == LOW) {
    pulseCount++;
  }
  lastRPMState = currentRPMState;

  if (millis() - lastMeasurement >= MEASUREMENT_INTERVAL) {
    rpmMeasured = (float)pulseCount * 60.0 / PULSES_PER_REV;
    pulseCount = 0;
    lastMeasurement = millis();
    updateLCD();
  }

  // --- Generovanie krokov ---
  if (motorEnabled) {
    digitalWrite(PUL_PIN, HIGH);
    delayMicroseconds(speedDelay * 5);
    digitalWrite(PUL_PIN, LOW);
    delayMicroseconds(speedDelay * 5);
  }
}

// --- Funkcia na aktualizáciu LCD ---
void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OTACKY/min: ");
  lcd.print((int)rpmMeasured);

  lcd.setCursor(0, 1);
  lcd.print("PULZY: ");
  lcd.print(speedDelay);
  lcd.print("us");

  lcd.setCursor(13, 1);
  if (motorEnabled)
    lcd.print(direction ? "->" : "<-");
  else
    lcd.print("OFF");
}
