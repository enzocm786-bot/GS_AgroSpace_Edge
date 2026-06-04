#define TEMP_PIN A0
#define SOIL_PIN A1

#define LED_PUMP_PIN 13
#define LED_ALERT_PIN 12
#define BUZZER_PIN 11

const float LIMITE_UMIDADE_SECO = 40.0;
const float LIMITE_TEMP_ALTA = 35.0;

void setup() {
  pinMode(LED_PUMP_PIN, OUTPUT);
  pinMode(LED_ALERT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {

  int valorTemp = analogRead(TEMP_PIN);
  float tensao = valorTemp * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100.0;

  int valorSolo = analogRead(SOIL_PIN);
  float umidade = valorSolo * 100.0 / 1023.0;

  if (umidade < LIMITE_UMIDADE_SECO) {
    digitalWrite(LED_PUMP_PIN, HIGH);
  } else {
    digitalWrite(LED_PUMP_PIN, LOW);
  }

  if (temperatura >= LIMITE_TEMP_ALTA && umidade < LIMITE_UMIDADE_SECO) {

    digitalWrite(LED_ALERT_PIN, HIGH);

    tone(BUZZER_PIN, 800);
    delay(200);
    noTone(BUZZER_PIN);

  } else {

    digitalWrite(LED_ALERT_PIN, LOW);
    noTone(BUZZER_PIN);

  }

  delay(500);
}
