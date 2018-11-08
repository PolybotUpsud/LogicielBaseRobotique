#include "pwm_lib.h"

using namespace arduino_due::pwm_lib;

pwm<pwm_pin::PWML4_PC21> pwm_moteur_gauche; /* PIN9 */
pwm<pwm_pin::PWML6_PC23> pwm_moteur_droit; /* PIN7 */

#define pinEnGauche 13
#define pinEnDroit 12
#define pinDirGauche 8
#define pinDirDroit 5

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);

  pinMode(pinEnGauche, OUTPUT);
  pinMode(pinEnDroit, OUTPUT);
  pinMode(pinDirGauche, OUTPUT);
  pinMode(pinDirDroit, OUTPUT);

  /* Initialisation PWM moteurs */
  pwm_moteur_gauche.start(0,0);
  pwm_moteur_droit.start(0,0);

  digitalWrite(pinEnGauche, HIGH);
  digitalWrite(pinEnDroit, HIGH);
  digitalWrite(pinDirGauche, HIGH);
  digitalWrite(pinDirDroit, HIGH);
}

void loop() {
  char cmd;
  
  if (Serial.available() > 0) {
    cmd = Serial.read();

    switch (cmd) {
      case 'a':
        digitalWrite(pinEnGauche, HIGH);
        digitalWrite(pinEnDroit, HIGH);
        break;
      case 'z':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, HIGH);
        digitalWrite(pinDirDroit, HIGH);
        pwm_moteur_gauche.set_period_and_duty(200000,200000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 'q':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, HIGH);
        digitalWrite(pinDirDroit, LOW);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 's':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, LOW);
        digitalWrite(pinDirDroit, LOW);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 'd':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, LOW);
        digitalWrite(pinDirDroit, HIGH);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
    }
  }
  if (Serial1.available() > 0) {
    cmd = Serial1.read();

    switch (cmd) {
      case 'a':
        digitalWrite(pinEnGauche, HIGH);
        digitalWrite(pinEnDroit, HIGH);
        break;
      case 'z':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, HIGH);
        digitalWrite(pinDirDroit, HIGH);
        pwm_moteur_gauche.set_period_and_duty(200000,200000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 'q':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, HIGH);
        digitalWrite(pinDirDroit, LOW);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 's':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, LOW);
        digitalWrite(pinDirDroit, LOW);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
      case 'd':
        digitalWrite(pinEnGauche, LOW);
        digitalWrite(pinEnDroit, LOW);
        digitalWrite(pinDirGauche, LOW);
        digitalWrite(pinDirDroit, HIGH);
        pwm_moteur_gauche.set_period_and_duty(100000,100000/2);
        pwm_moteur_droit.set_period_and_duty(100000,100000/2);
        break;
    }
  }
}
