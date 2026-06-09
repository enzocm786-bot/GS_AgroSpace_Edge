// AgroSpace — Estação de Monitoramento Agrícola
// Edge Computing & Computer Systems

#define TEMP_PIN      A0
#define SOIL_PIN      A1
#define LED_PUMP_PIN  13
#define LED_ALERT_PIN 12
#define BUZZER_PIN    11

// Limites calibrados conforme modelo matemático do grupo
const float LIMITE_UMIDADE_SECO = 40.0;  // % — abaixo disso, aciona irrigação
const float LIMITE_TEMP_ALTA    = 35.0;  // °C — acima disso com solo seco = risco crítico

void setup() {
  Serial.begin(9600);

  pinMode(LED_PUMP_PIN,  OUTPUT);
  pinMode(LED_ALERT_PIN, OUTPUT);
  pinMode(BUZZER_PIN,    OUTPUT);

  Serial.println("=== AgroSpace iniciado ===");
  Serial.println("Temp(C) | Umidade(%) | Irrigacao | Alerta");
  Serial.println("------------------------------------------------");
}

void loop() {
  // --- Leitura de temperatura (TMP36) ---
  int rawTemp    = analogRead(TEMP_PIN);
  float tensao   = rawTemp * (5.0 / 1023.0);
  float temp     = (tensao - 0.5) * 100.0;

  // --- Leitura de umidade do solo (potenciômetro) ---
  int rawSolo    = analogRead(SOIL_PIN);
  float umidade  = rawSolo * 100.0 / 1023.0;

  // --- Controle de irrigação ---
  bool irrigando = (umidade < LIMITE_UMIDADE_SECO);
  digitalWrite(LED_PUMP_PIN, irrigando ? HIGH : LOW);

  // --- Detecção de risco crítico ---
  bool alerta = (temp >= LIMITE_TEMP_ALTA) && irrigando;
  digitalWrite(LED_ALERT_PIN, alerta ? HIGH : LOW);

  if (alerta) {
    tone(BUZZER_PIN, 800);
    delay(200);
    noTone(BUZZER_PIN);
  } else {
    noTone(BUZZER_PIN);
  }

  // --- Telemetria serial (lida pelo monitor ou integrada a sistemas externos) ---
  Serial.print(temp, 1);
  Serial.print(" C     | ");
  Serial.print(umidade, 1);
  Serial.print("%      | ");
  Serial.print(irrigando ? "LIGADA    " : "DESLIGADA ");
  Serial.print(" | ");
  Serial.println(alerta   ? "CRITICO" : "OK");

  delay(1000); // ciclo de 1 segundo
}
