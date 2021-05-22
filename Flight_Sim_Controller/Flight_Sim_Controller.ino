// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

#define ROLL_PIN    A3
#define PITCH_PIN   A2
#define YAW_PIN     A1

Joystick_ Joystick (  JOYSTICK_DEFAULT_REPORT_ID,
                      JOYSTICK_TYPE_JOYSTICK,
                      0,     // Number of available buttons
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

//Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;

void setup() {

  pinMode(ROLL_PIN, INPUT_PULLUP);
  pinMode(PITCH_PIN, INPUT_PULLUP); 
  pinMode(YAW_PIN, INPUT_PULLUP);
  
  Joystick.setXAxisRange(0, 1023); 
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);

  Joystick.begin();
}

void loop() {
  
// Read Joystick
  JoystickX = analogRead(ROLL_PIN); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(PITCH_PIN); // Hall effect sensor connects to this analog pin

// Read Rudder Pedals
  JoystickZ = analogRead(YAW_PIN); // Hall effect sensor connects to this analog pin
   
// Output Controls
  Joystick.setXAxis(JoystickX);
  Joystick.setYAxis(JoystickY);
  Joystick.setZAxis(JoystickZ);

  Joystick.sendState();
} 
