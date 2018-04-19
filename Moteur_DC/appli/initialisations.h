/*
 * initialisations.h
 *
 *  Created on: 17 avr. 2018
 *      Author: Team Aéroglisseur Connecté
 */

#ifndef INITIALISATIONS_H_
#define INITIALISATIONS_H_

/*
 *		! -- ajouter des #include xx.h si nécessaire -- !
 */

/**
 * @brief	Fonction regroupant toutes les initialisations nécessaires à la carte
 */
void Init_carte(void){

		HAL_Init();			//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
		BSP_GPIO_Enable();	//Activation des périphériques GPIO
		SYS_ClockConfig();	//Configuration des horloges

//------------------------------------------------------------------------//

		/**
		 * @brief	xxx
		 */

//------------------------------------------------------------------------//

		/**
		 * @brief	Initialise l'USARTx - 8N1 - vitesse des bits (baudrate) indiqué en paramètre
		 * @func	void UART_init(uint8_t uart_id, uart_interrupt_mode_e mode)
		 * @param	uart_id est le numéro de l'UART concerné :
		 * 				UART1_ID
		 * 				UART2_ID
		 * 				UART3_ID
		 * @param	baudrate indique la vitesse en baud/sec
		 * 				115200	vitesse proposée par défaut
		 * 				9600	vitesse couramment utilisée
		 * 				19200	...
		 * @post	Cette fonction initialise les broches suivante selon l'USART choisit en parametre :
		 * 				USART1 : Rx=PA10 et Tx=PA9 		ou avec remap : Rx=PB7 et Tx=PB6
		 * 				USART2 : Rx=PA3 et Tx=PA2 		ou avec remap : Rx=PD6 et Tx=PD5
		 * 				USART3 : Rx=PB11 et Tx=PB10 	ou avec remap : Rx=PD9 et Tx=PD8
		 * 				La gestion des envois et reception se fait en interruption.
		 * 				Attention, les pins PA2 et PA3 ne sont pas reliées jusqu'au connecteur de la Nucleo.
		 * 				Ces broches sont redirigées vers la sonde de débogage, la liaison UART étant ensuite encapsulée sur l'USB vers le PC de développement.
		 *
		 *	//UART_init(uart_id, baudrate);
		 *
		 */

		//UART_init(uart_id, baudrate);

		SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);	//Indique que les printf sortent vers le périphérique UART2.

//------------------------------------------------------------------------//

		/**
		 * @brief Initialisations liées aux moteurs
		 */
		MOTOR_init(1);	//init le moteur n°1

//------------------------------------------------------------------------//

		/**
		 * @brief	xxx
		 */

//------------------------------------------------------------------------//

		/**
		 *@brief	xxx
		 */

//------------------------------------------------------------------------//

}

#endif /* INITIALISATIONS_H_ */
