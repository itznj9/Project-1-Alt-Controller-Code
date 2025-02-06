#include <AltController.h>


AltController controller;

// Define pin numbers for the buttons (coins)
const int buttonPin1 = 2;  // Pin for first coin 
const int buttonPin2 = 3;  // Pin for second coin 
void setup() {
  Serial.begin(9600);  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  
  controller.addMacro(2, {KEY_LEFT_CTRL, 's'}, 100);  // Sends Ctrl + S (Save)
  controller.addMacro(3, {KEY_LEFT_CTRL, 'z'}, 100);  // Sends Ctrl + Z (Undo)
}

void loop() {
  int stateButton1 = digitalRead(buttonPin1);  
  int stateButton2 = digitalRead(buttonPin2); 
  
  Serial.print("Button 1 state: ");
  Serial.println(stateButton1);
  Serial.print("Button 2 state: ");
  Serial.println(stateButton2);
  
  if (stateButton1 == LOW) {
    Serial.println("Save");  // Sends "Save" to the Serial Monitor
    
  }
  
  if (stateButton2 == LOW) {
    Serial.println("Undo");  // Sends "Undo" to the Serial Monitor
    
  }
controller.update();
}
