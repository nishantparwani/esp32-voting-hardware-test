// ----------------------------
// ESP32 Voting Buttons + Buzzer Test
// ----------------------------

// Pin definitions
const int buttonPins[4] = {13, 14, 27, 26}; // Buttons 1–4
const int buzzerPin = 25;                   // Buzzer

// Variables to store button states
int buttonState[4] = {0, 0, 0, 0};
int lastButtonState[4] = {0, 0, 0, 0};

void setup() {
  Serial.begin(115200);                     // Serial monitor for debugging
  
  // Set button pins as INPUT_PULLDOWN
  for(int i = 0; i < 4; i++){
    pinMode(buttonPins[i], INPUT_PULLDOWN);
  }
  
  pinMode(buzzerPin, OUTPUT);               // Buzzer as output
  digitalWrite(buzzerPin, LOW);             // Keep buzzer off initially
  
  Serial.println("Voting buttons test started!");
}

void loop() {
  for(int i = 0; i < 4; i++){
    buttonState[i] = digitalRead(buttonPins[i]);
    
    // Detect button press (LOW → HIGH)
    if(buttonState[i] == HIGH && lastButtonState[i] == LOW){
      Serial.print("Button ");
      Serial.print(i+1);
      Serial.println(" pressed!");
      
      // Buzz briefly
      digitalWrite(buzzerPin, HIGH);
      delay(200);            // 200ms beep
      digitalWrite(buzzerPin, LOW);
    }
    
    lastButtonState[i] = buttonState[i];
  }
}
