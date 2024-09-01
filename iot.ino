#define TdsSensorPin A1
#define TurbiditySensorPin A0

float temperature = 25, tdsValue = 0;

void setup() {
 Serial.begin(115200);
}

void loop() {
 // TDS Sensor Reading
 int sensorValue = analogRead(TdsSensorPin);
 float voltage = sensorValue * (5.0 / 1024.0); // Convert analog reading to voltage
 float tdsValue = voltage * 1000; // Convert voltage to TDS value (assuming linear relationship)
 
 Serial.print("TDS Value: ");
 Serial.print(tdsValue, 2); // Print TDS value with 2 decimal places
 Serial.println(" ppm");

 // Chlorine level calculation
 float chlorineLevel = tdsValue * 0.001; // Convert TDS to chlorine level (assuming linear relationship)
 Serial.print("Chlorine Level: ");
 Serial.print(chlorineLevel, 2); // Print chlorine level with 2 decimal places
 Serial.println(" ppm");

 // Turbidity Sensor Reading
 int turbidityValue = analogRead(TurbiditySensorPin);
 float turbidityVoltage = turbidityValue * (5.0 / 1024.0); // Convert analog reading to voltage
 
 delay(500);
}


