#include <Arduino.h>

#include "define_io.h"

// time count
unsigned long tTime[3] = {0,0};
int sec = 1000;
// Set the PWM duty cycle (out of 255)
void spinspeed(int spin_speed_feed, int spin_speed_spin){
  // Set the direction of the motor
  //Spin
  digitalWrite(MOTOR_PIN_SP, HIGH);
  digitalWrite(MOTOR_PIN_SN, LOW);
  analogWrite(MOTOR_PWM_PINS, spin_speed_spin);
  // Feed
  digitalWrite(MOTOR_PIN_FP, HIGH);
  digitalWrite(MOTOR_PIN_FN, LOW);
  analogWrite(MOTOR_PWM_PINF, spin_speed_feed);
}

void setup() {
  // Set Motor Driver pins to output mode
  // SPIN
  pinMode(MOTOR_PIN_SP, OUTPUT);
  pinMode(MOTOR_PIN_SN, OUTPUT);
  pinMode(MOTOR_PWM_PINS, OUTPUT);
  // FEED
  pinMode(MOTOR_PIN_FP, OUTPUT);
  pinMode(MOTOR_PIN_FN, OUTPUT);
  pinMode(MOTOR_PWM_PINF, OUTPUT);

}

void loop() {

  unsigned long current_time = millis(); // The start time in milliseconds

  // ====================== every 20 sec, change duty
  if(current_time - tTime[0] < 20*sec){ // 20 sec
    spinspeed(255,64); // 25%
  }

  if((current_time - tTime[0] > 20*sec) && (current_time - tTime[0] < 40*sec)){
    spinspeed(255,128); // 50%
  }

  if((current_time - tTime[0] >= 40*sec) && (current_time - tTime[0] < 60*sec)){
    spinspeed(255,191); // 75%
  }

  if((current_time - tTime[0] >= 60*sec) && (current_time - tTime[0] < 80*sec)){
    spinspeed(255,255); // 100%
  }

  if((current_time - tTime[0] >= 80*sec) && (current_time - tTime[0] < 100*sec)){
    spinspeed(255,255); // 100%
  }

  if((current_time - tTime[0] >= 100*sec) && (current_time - tTime[0] < 120*sec)){
    digitalWrite(MOTOR_PIN_SP, LOW);
    digitalWrite(MOTOR_PIN_SN, LOW);
    digitalWrite(MOTOR_PIN_FP, LOW);
    digitalWrite(MOTOR_PIN_FN, LOW);
  }
  // ======================

  if(current_time - tTime[0] >= 120*sec){
    tTime[0]=current_time;
  }
  
}