// Reconstrucción de prueba inicial: 1 sensor KY-035 directamente a A0.
// Alimentación nominal 3.3 V. No ejecutar hasta validación eléctrica.
const int sensor = A0;
void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  Serial.println("PRUEBA CON 1 SENSOR HALL");
}
void loop() {
  int valor = analogRead(sensor);
  float voltaje = valor * (3.3 / 4095.0);
  Serial.print("Sensor 1 | RAW: "); Serial.print(valor);
  Serial.print(" | Voltaje: "); Serial.print(voltaje, 3);
  Serial.println(" V");
  delay(1000);
}
