// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

#define ROLL_PIN    A3
#define PITCH_PIN   A2
#define YAW_PIN     A1
#define BUTTON_1    9

Joystick_ Joystick (  JOYSTICK_DEFAULT_REPORT_ID,
                      JOYSTICK_TYPE_JOYSTICK,
                      1,     // Number of available buttons
                      0,      // Number of available hat switches
                      true,   // X Axis
                      true,   // Y Axis
                      true,   // Z Axis
                      false,  // X Axis Rotation
                      false,  // Y Axis Rotation
                      false,  // Z Axis Rotation
                      false,  // Rudder
                      false,  // Throttle
                      false,  // Accelerator
                      false,  // Brake
                      false   // Steering
                     ); 
 
int JoystickX;
int JoystickY;
int JoystickZ;

int lastButton1State = 0;

void setup() {

  pinMode(ROLL_PIN, INPUT_PULLUP);
  pinMode(PITCH_PIN, INPUT_PULLUP); 
  pinMode(YAW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_1, INPUT_PULLUP);  
  
  Joystick.setXAxisRange(0, 1023); 
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);

  Joystick.begin();
}

void loop() {
  
  // X axis is used for the plane roll
  JoystickX = analogRead(ROLL_PIN); // Hall effect sensor connects to this analog pin
  Joystick.setXAxis(JoystickX);

  // Y axis is used for the plane pitch
  JoystickY = analogRead(PITCH_PIN); // Hall effect sensor connects to this analog pin
  Joystick.setYAxis(JoystickY);
  
  // Z axis is used for rudder pedals
  JoystickZ = analogRead(YAW_PIN); // Hall effect sensor connects to this analog pin
  Joystick.setZAxis(JoystickZ);
   
  // Read buttons state
  int currentButton1State = !digitalRead(BUTTON_1);
  if(currentButton1State != lastButton1State) {
    Joystick.setButton(0, currentButton1State);
    lastButton1State = currentButton1State;
    // Pole delay/debounce
    delay(10);    
  }  

  Joystick.sendState();
} 
