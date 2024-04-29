#include <Servo.h>
//initialization of variables
// Task 1: Door control with ultrasonic sensor
Servo servo1;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;

// Task 2: LDR and LED control
int ldrPin = 6; // LDR pin
int ledPin = 13; // LED pin

// Task 3: Buzzer control with analog sensor
#define BUZZER_PIN 3

// Task 4: Temp sense and actuate servo and buzzer+LED
int ThermistorPin = 5;
int Vo;
float R1 = 10000; //resistor in the circuit
float logR2, R2;
float T; // Moved T declaration here
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
//set up pins
void setup() {
  // Task 1: Door control with ultrasonic sensor
  servo1.attach(7);//attach servo to pin 7 of arduino
  pinMode(trigPin, OUTPUT); //trigger the pins in ultrasonic
  pinMode(echoPin, INPUT);

  // Task 2: LDR and LED control
  Serial.begin(9600);    
  pinMode(ldrPin, INPUT); //sensor input
  pinMode(ledPin, OUTPUT); //led output

  // Task 3: Buzzer control with analog sensor
  pinMode(BUZZER_PIN, OUTPUT); //buzz output

  // Initialize Serial for temperature sensor
  Serial.begin(9600); 
}
//Loop to run the model
void loop() {
  // Task 1: Door control with ultrasonic sensor
  ultra_sonic();
  servo1.write(90); // 90 is closed door
  while (distance <= 10 ) { //continues checking is d <10
    ultra_sonic(); //if yes, then again checks d
    servo1.write(0); //  0 degrees is the open position
    delay(2000);     // Delay for 2 seconds before closing the door
     // Move back to closed position
  }
  
  servo1.write(90); 
    

  // Task 2: LDR and LED control
  int ldrValue = digitalRead(ldrPin); //reads pin val
  Serial.print("LDR: "); 
  Serial.println(ldrValue);
  if (ldrValue == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED if it's dark
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED if it's bright
  }

  // Task 3: Buzzer control with analog sensor
  int sensorValue = analogRead(A0); // read analog sensor value
  Serial.print("Sensor gas: "); 

  Serial.println(sensorValue);
  if (sensorValue > 500) {  // threashold value gas sensor
    tone(BUZZER_PIN, 50);
  } else {
    noTone(BUZZER_PIN); // Stop generating the tone when condition is not met
  }
  
  // Task 4: Temperature decision
  temp();
  if (T > 100) {//threshold thermistor
    tone(BUZZER_PIN, 500); 
    servo1.write(0);
    delay(10000);
    
    
  } else {
    noTone(BUZZER_PIN);
    servo1.write(90);
  }

  delay(1000); // Add a delay 
}

// Ultrasonic sensor function
void ultra_sonic() {
  digitalWrite(trigPin, LOW); //initiates sending signal process
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//send signal
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //pulse complete
  duration = pulseIn(echoPin, HIGH); //when echo high- receive then measure time
  distance = duration * 0.034 / 2; //sound speed .034 m.micro sec
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("----");
  
}

// Temperature sensor function
void temp() {
  Vo = analogRead(ThermistorPin); //voltage level
  //voltage divider
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculates resistance of thermistor
  logR2 = log(R2); //use log to linialize the relation of volt and temp
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); //Steinhart-Hart equation for thermistors ....temperature in Kelvin (K).
  T = T - 273.15;//c
  T = (T * 9.0) / 5.0 + 32.0; //F

  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" F");

  delay(500);
}
