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
	/**
	 * @brief	Initialisations de la carte, INDISPENSABLE, y mettre les lignes de code appelées unne seule fois
	 * @func Faire propre dans le main.c, pour ne pas s'emmêler les pinceaux avec trop de lignes
	 */
	Init_carte();

	/**
	 * @brief Lancement du moteur
	 */
	MOTOR_set_duty(20, MOTOR1);	//changement du duty cycle -/+100 %, changement de sens de rotation possible

	while(1)
	{
		/**
		 * @brief	Envoi une chaine de caractere sur l'USARTx. Fonction BLOCANTE si un caractère est deja en cours d'envoi.
		 * @func 	void UART_putc(UART_HandleTypeDef * UART_Handle, char c)
		 * @param	str : la chaine de caract�re � envoyer
		 * @param	USARTx : USART1, USART2 ou USART6
		 */
	//	UART_puts(UART1_ID, *test, USART1);

		//test 6 git

	}
}






























