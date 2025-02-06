#include <AltController.h>

// Initialize the controller object
AltController controller;

// Define pin numbers for the buttons (coins)
const int buttonPin1 = 2;  // Pin for first coin (button)
const int buttonPin2 = 3;  // Pin for second coin (button)

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  pinMode(buttonPin1, INPUT_PULLUP);  // Use internal pull-up resistors
  pinMode(buttonPin2, INPUT_PULLUP);  // Use internal pull-up resistors
  controller.addMacro(2, {KEY_LEFT_CTRL, 's'}, 100);  // Sends Ctrl + S (Save)
  controller.addMacro(3, {KEY_LEFT_CTRL, 'z'}, 100);  // Sends Ctrl + Z (Undo)
}

void loop() {
  // Read the state of the buttons (coins) and print to the Serial Monitor
  int stateButton1 = digitalRead(buttonPin1);  // Read the state of the first coin
  int stateButton2 = digitalRead(buttonPin2);  // Read the state of the second coin
  
  // Print the state of button1 and button2 to the Serial Monitor for debugging
  Serial.print("Button 1 state: ");
  Serial.println(stateButton1);
  Serial.print("Button 2 state: ");
  Serial.println(stateButton2);
  
  // Check if the first coin (button) is pressed (state LOW because of INPUT_PULLUP)
  if (stateButton1 == LOW) {
    Serial.println("Save");  // Sends "Save" to the Serial Monitor
    
  }
  
  // Check if the second coin (button) is pressed (state LOW because of INPUT_PULLUP)
  if (stateButton2 == LOW) {
    Serial.println("Undo");  // Sends "Undo" to the Serial Monitor
    
  }
controller.update();
}
