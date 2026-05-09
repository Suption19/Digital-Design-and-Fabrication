const int echoPin = 9;  
const int trigPin = 10; 

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  
  // URM37 often likes the Trigger to start HIGH
  digitalWrite(trigPin, HIGH); 
  
  Serial.println("--- URM37 V5 'Deep' Test ---");
}

void loop() {
  // Trigger pulse: LOW for 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);

  // Measure the HIGH pulse on Echo
  // The URM37 can take a while, so we use a 50ms timeout
  long duration = pulseIn(echoPin, LOW, 50000); 
  
  // Note: On some URM37 V5, the Echo signal is INVERTED.
  // If the above doesn't work, we will try: pulseIn(echoPin, HIGH, 50000);

  int distance = duration / 50; // URM37 formula is slightly different

  if (duration == 0) {
    Serial.println("No Pulse Detected. Try swapping Pin 9 and 10?");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    // Light up Pin 13 if hand is close
    if (distance > 0 && distance < 20) digitalWrite(13, HIGH);
    else digitalWrite(13, LOW);
  }

  delay(300); 
}
