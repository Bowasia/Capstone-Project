#include <Arduino.h>

#include "define_io.h"

// speed set up
// Set the PWM duty cycle to 50% (out of 255)
int spin_speed = 128;
// ------

void setup() {
  // Set Motor Driver pins to output mode
  // SPIN
  pinMode(MOTOR_PIN_SP, OUTPUT);
  pinMode(MOTOR_PIN_SM, OUTPUT);
  pinMode(MOTOR_PWM_PINS, OUTPUT);

}

void loop() {
  // Set the direction of the motor
  digitalWrite(MOTOR_PIN_SP, LOW);
  digitalWrite(MOTOR_PIN_SM, LOW);
  // Wait for 2 seconds
  delay(2000);

  // Set the direction of the motor
  digitalWrite(MOTOR_PIN_SP, HIGH);
  digitalWrite(MOTOR_PIN_SM, LOW);
  analogWrite(MOTOR_PWM_PINS, spin_speed);

  // Set the PWM duty cycle to 75% (out of 255)
  analogWrite(MOTOR_PWM_PINS, 192);

  // Wait for 2 seconds
  delay(2000);
}