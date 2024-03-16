const int sensorPin = A0;  // LM35 temperature sensor connected to Analog pin A0
const int ledPin = 13;     // Onboard LED connected to digital pin 13

unsigned long previousMillis = 0;  // Stores the time when the LED was last toggled
const long intrvLow = 250;      // Interval for blinking LED when temperature is below 30°C
const long intrvHigh = 500;     // Interval for blinking LED when temperature is above 30°C

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  int temperature = readTemperature();  // Read temperature from LM35 sensor

  // Check if temperature is below 30°C
  if (temperature < 30) {
    // Blink LED with 250 ms interval
    blinkLED(intrvLow);
  } 
  // Check if temperature is above or equal to 30°C
  else {
    // Blink LED with 500 ms interval
    blinkLED(intrvHigh);
  }

  // Print temperature to serial monitor
  Serial.print("Temperature: " + temprature );
  Serial.println(" °C");
}

int readTemperature() {
  // Read analog value from LM35 sensor
  int sensorValue = analogRead(sensorPin);
  
  // Convert analog value to temperature in Celsius
  float temperature = (sensorValue * 5.0 / 1023) * 100;

  return (int)temperature; // Return temperature as integer
}

void blinkLED(long interval) {
  unsigned long currentMillis = millis(); // Get the current time

  // Check if it's time to toggle the LED
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the LED was toggled
    previousMillis = currentMillis;

    // Toggle the LED state
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}



