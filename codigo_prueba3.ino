// Reconstrucción: 3 sensores en canales C0 a C2.
// ATENCIÓN: el IDC necesita breakout; NO conectar VCC/GND a canales Cx.
const int SIG = A0;
const int S0 = D5;
const int S1 = D6;
const int S2 = D9;
const int S3 = D10;

void multiplexor(int canal) {
  // Selección binaria de canal en HP4067. EN va físicamente a GND.
  digitalWrite(S0, (canal & 1) ? HIGH : LOW);
  digitalWrite(S1, (canal & 2) ? HIGH : LOW);
  digitalWrite(S2, (canal & 4) ? HIGH : LOW);
  digitalWrite(S3, (canal & 8) ? HIGH : LOW);
}
void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  pinMode(S0, OUTPUT); pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT); pinMode(S3, OUTPUT);
  Serial.println("PRUEBA SENSORES HALL");
}

void loop() {
  int valorMayor = -1;
  int sensorMayor = 0;
  Serial.println("------------------------------");
  Serial.println("LECTURA DE 3 SENSORES");
  for (int i = 0; i < 3; i++) {
    multiplexor(i);
    delay(10);
    analogRead(SIG); // lectura de descarte tras cambiar canal
    delay(2);
    int valor = analogRead(SIG);
    float voltaje = valor * (3.3 / 4095.0);
    Serial.print("Sensor "); Serial.print(i + 1);
    Serial.print(" | RAW: "); Serial.print(valor);
    Serial.print(" | Voltaje: "); Serial.print(voltaje, 3);
    Serial.println(" V");
    if (valor > valorMayor) {
      valorMayor = valor;
      sensorMayor = i + 1;
    }
  }
  Serial.print("SENSOR CON MAYOR LECTURA: ");
  Serial.println(sensorMayor);
  Serial.print("VALOR MAYOR: "); Serial.println(valorMayor);
  Serial.println();
  delay(1000);
}
