/**
  ******************************************************************************
  * @file    main.c
  * @author  Team Aéroglisseur Connecté
  * @version V1.0
  * @date    19/04/2018
  * @brief   Fonction main
  ******************************************************************************
*/

#include "stm32f1xx_hal.h"
#include "stm32f1xx_nucleo.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "macro_types.h"
#include "stm32f1_gpio.h"
#include "stm32f1_timer.h"
#include "test.h"
#include "stm32f1_motorDC.h"
#include "stm32f1_pwm.h"
#include "initialisations.h"
#include "stm32f1xx_hal_tim.h"
#include <stdio.h>
#include <stdint.h>
#include "stm32f1_uart.h"

int main(void)
{
	int16_t Duty1,Duty2,Duty3,Duty4;
	/**
	 * @brief	Initialisations de la carte, INDISPENSABLE, y mettre les lignes de code appelées une seule fois
	 * @func Faire propre dans le main.c, pour ne pas s'emmêler les pinceaux avec trop de lignes
	 */
	Init_carte();

	/**
	 * @brief Lancement du moteur
	 */
	//Le rapport cycique définit içi influe sur la vitesse de rotation du moteur.
	//changement du duty cycle -/+100 %, changement de sens de rotation possible
	// Motor1 = Moteur S / Motor2 = Moteur G / Motor3 = Moteur C / Motor 4 = Moteur D
	Duty1 = 20;
	Duty2 = 20;
	Duty3 = 60;
	Duty4 = 80;

	//Application du rapport cyclique pour controle des différents moteurs
	MOTOR_set_duty(Duty1, MOTOR1);	//PA8
	MOTOR_set_duty(Duty2, MOTOR2);	//PA9
	MOTOR_set_duty(Duty3, MOTOR3);	//PA10
	MOTOR_set_duty(Duty4, MOTOR4);	//PA11

	while(1)
	{
		//testmaj
		/**
		 * @brief a
		 */

	}
}






