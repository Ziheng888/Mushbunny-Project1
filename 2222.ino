/*
//Project1: Mushbunny
//Ziheng Qu
//DIGF-6037 Creation & Computation
//Credits:
Based on: https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
AnalogWrite section adapted from: https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogWriteMega
*/


const int sensorInput = A1;  // Analog input pin for the pressure sensor
const int flashTime = 3;   // Time delay for LED brightness changes
const int thisPin = 9;   // Pin for the LED
int sensorValue = 0;   // Variable to store the sensor value

// the setup routine runs once when you press reset:
void setup() {
    // use a for loop to initialize each pin as an output:
    pinMode(thisPin, OUTPUT);
    pinMode(sensorInput, INPUT);
  }

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(sensorInput);  // read the input on analog pin
  Serial.print(sensorValue);
  Serial.println();
  delay(50); // delay in between reads for stability

 // Check if the sensor value exceeds the threshold (500 in this case)
  if(sensorValue > 500){
 // Gradually increase the brightness of the LED
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(thisPin, brightness); 
      delay(flashTime); 
    }
 // Gradually decrease the brightness of the LED
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness); 
      delay(flashTime); 
    }
  } else {
  // If sensor value is below the threshold, turn off the LED
    analogWrite(thisPin, 0);
  }
}