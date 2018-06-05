/**
 * demo_motor.c
 *
 *  Created on: 27 octobre 2015
 *      Author: S. Poiraud
 */

/*
 * Ce module logiciel est destin� au pilotage de moteur DC � travers un pont en H BD6221F-E2
 * 	(ou mod�le similaire en terme de signaux de commande)
 *
 * Ce module utilise le pilote stm32f1_pwm.h
 *
 * Table de v�rit� des signaux de commande de ce pont en H BD6221 :
 *
 * 	(lorsque l'entr�e Vref est reli�e � Vcc)
 *
 * 		Rin		Fin
 * 		0		0		moteur en roue libre
 * 		0		pwm		moteur en marche avant, 	vitesse proportionelle au rapport cyclique du signal pwm
 * 		pwm		0		moteur en marche arri�re, 	vitesse proportionelle au rapport cyclique du signal pwm
 * 		1		1		moteur en court-circuit (freinage maximal)
 *
 * 		Pour un ch�ssis mobile, et dans la majorit� des fonctionnement, on utilise les 3 premi�res lignes de cette table de v�rit�.
 * 		Selon le signe de la variable "duty", ce module logiciel est donc con�u pour produire  :
 * 					-> une PWM vers une broche Fin, et un 0 logique vers la broche Rin
 * 			OU BIEN -> une PWM vers une broche Rin, et un 0 logique vers la broche Fin
 *
 *
 * Les ports utilis�s par ce module logiciel sont impos�s.
 * Il est possible de les changer en modifiant le contenu des fonctions MOTOR_init et MOTOR_set_duty.
 */

/* Pour le module TB6612F-NG
 * Table de v�rit� des signaux de commande de ce pont en H TB6612F-NG
 * 	PWM 	AIN1	AIN2
 * 	1		0		1		moteur en sens horaire inverse
 *  1		1		0		moteur en sens horaire
 *  1       0       0		moteur en roue libre
 *  0 		x		x		moteur en court-circuit (freinage maximal) !!
 *  x		1		1		moteur en court-circuit (freinage maximal) !!
 *
 * Il ne faut donc pas utiliser la broche nomm�e "PWM" pour y envoyer un signal PWM... sinon on alterne avec un �tat court-circuit.
 * Pour cela, pour une rotation en sens horaire : on envoie un signal PWM sur AIN1 en maintenant AIN2 � 0 et PWM � 1.
 *            pour une rotation anti-hoaire     : on envoie un signal PWM sur AIN2 en maintenant AIN1 � 0 et PWM � 1.
 *  Exemple fonctionner de Branchements pouvant servir de base:
 *  TB6612F-NG			Nucleof103
 *  VM				--	5V ou toute tension "puissance" correspondant � la vitesse max du moteur
 *  VCC				--  3.3V
 *  GND				--	GND (toutes les pins GND du module TB6612F-NG sont reli�es entre elles)
 * 	STBY			--	3.3V
 * 	PWMA			--  3.3V
 * 	AIN1			--	PB13 - par exemple... (pour sortir un signal PWM   ou bien   0)
 * 	AIN2			--	PA8  - par exemple... (pour sortir 0               ou bien   un signal PWM)
 * 	AO1 et AO2		--	Reli�es aux broches du moteur
 */
#include "config.h"
#if USE_MOTOR_DC
#include "stm32f1_motorDC.h"
#include "stm32f1_pwm.h"
#include "stm32f1_gpio.h"
#include "stm32f1xx_hal.h"




/**
 * @brief 	Cette fonction est une machine a etat qui pr�sente un exemple d'utilisation de ce module.
 * @func 	running_e DEMO_MOTOR_statemachine (bool_e ask_for_finish, char touch_pressed)
 * @param 	ask_for_finish : demande que la machine a �tat se termine.
 * @param	touch_pressed : caract�re entr� par l'utilisateur. NULL si aucun caract�re.
 * @return	cette fonction retourne un element de l'enumeration running_e (END_OK= l'application est quittee avec succes ou IN_PROGRESS= l'application est toujours en cours)
 */
running_e DEMO_MOTOR_statemachine (bool_e ask_for_finish, char touch_pressed)
{
	typedef enum
	{
		INIT = 0,
		DISPLAY,
		ADJUST_PWM,
		CLOSE
	}state_e;
	running_e ret = IN_PROGRESS;
	static state_e state = INIT;
	switch(state)
	{
		case INIT:
			MOTOR_init(4);

			state = DISPLAY;
			break;
		case DISPLAY:{
			printf("TIM1 / Channels 1, 2, 3, 4, 1N, 2N, 3N, 4N\n");
			printf("Touch -> %% PWM\n");
			uint8_t i;
			for(i=0;i<=9;i++)
				printf("   %d  -> %3d%%\n", i, i*10);
			printf("   *  -> *-1 %%\n");
			printf("   +  -> n+1%%\n");
			printf("   -  -> n-1%%\n");
			for(i=0;i<4;i++)
				printf("   %c  -> Channel %d\n", 'A'+i, i+1);
			state = ADJUST_PWM;
			break;}
		case ADJUST_PWM:{
			static int8_t duty = 50;
			static motor_e motor = TIM_CHANNEL_1;
			bool_e duty_updated = FALSE;
			bool_e motor_updated = FALSE;

			switch(touch_pressed)
			{
				case '+':	if(duty<100)		duty++;		duty_updated = TRUE;	break;
				case '-':	if(duty>-100)		duty--;		duty_updated = TRUE;	break;
				case '0':	duty=0; 			duty_updated = TRUE;	break;
				case '1':	duty=10; 			duty_updated = TRUE;	break;
				case '2':	duty=20; 			duty_updated = TRUE;	break;
				case '3':	duty=30; 			duty_updated = TRUE;	break;
				case '4':	duty=40; 			duty_updated = TRUE;	break;
				case '5':	duty=50; 			duty_updated = TRUE;	break;
				case '6':	duty=60; 			duty_updated = TRUE;	break;
				case '7':	duty=70; 			duty_updated = TRUE;	break;
				case '8':	duty=80; 			duty_updated = TRUE;	break;
				case '9':	duty=90; 			duty_updated = TRUE;	break;
				case '*':	duty=-duty; 		duty_updated = TRUE;	break;
				case 'a':	case 'A':	motor = MOTOR1;	motor_updated = TRUE;	break;
				case 'b':	case 'B':	motor = MOTOR2;	motor_updated = TRUE;	break;
				case 'c':	case 'C':	motor = MOTOR3;	motor_updated = TRUE;	break;
				case 'd':	case 'D':	motor = MOTOR4;	motor_updated = TRUE;	break;
				default:												break;
			}

			if(motor_updated)
			{
				printf("Motor %d\n",motor+1);
			}
			if(duty_updated)
			{
				MOTOR_set_duty((int16_t)duty, motor); // On applique ce pourcentage au PWM
				printf("Motor %d%c -> %3d%%\n", motor+1, (duty<0)?'N':' ', duty);
			}

			if(ask_for_finish)
				state = CLOSE;
			break;}
		case CLOSE:

			state = INIT;
			ret = END_OK;
			break;
		default:
			break;
	}

	return ret;
}


#define	PWM_PERIOD	50		//P�riode du signal PWM, en microsecondes
							//[50us <=> 20kHz, fr�quence humainement inaudible et �lectroniquement pas trop �lev�e]

/** @brief Fonction qui configure et initialise les timers 1 et 2... pour les 8 signaux indiqu�s.
 * @func void MOTOR_init(uint8_t nb_motors)
 */
void MOTOR_init(uint8_t nb_motors)
{
	//Initialisation des p�riph�riques TIMERS, configur�s en production de signaux PWM, sorties � 0.
	switch(nb_motors) {
		case 4 :
			PWM_run(TIMER1_ID, TIM_CHANNEL_4,FALSE,PWM_PERIOD,0, FALSE);	//1.CH4
			PWM_run(TIMER2_ID, TIM_CHANNEL_4,FALSE,PWM_PERIOD,0, FALSE);	//2.CH4   ATTENTION, le canal CH4_N �tant innaccessible sur le Timer 1, on utilise ici un second timer !
		case 3 :
			PWM_run(TIMER1_ID, TIM_CHANNEL_3,FALSE,PWM_PERIOD,0, FALSE);	//1.CH3
			PWM_run(TIMER1_ID, TIM_CHANNEL_3,TRUE,PWM_PERIOD,0, FALSE);	//1.CH3N
		case 2 :
			PWM_run(TIMER1_ID, TIM_CHANNEL_2,FALSE,PWM_PERIOD,0, FALSE);	//1.CH2
			PWM_run(TIMER1_ID, TIM_CHANNEL_2,TRUE,PWM_PERIOD,0, FALSE);	//1.CH2N
		case 1 :
			PWM_run(TIMER1_ID, TIM_CHANNEL_1,FALSE,PWM_PERIOD,0, FALSE);	//1.CH1
			PWM_run(TIMER1_ID, TIM_CHANNEL_1,TRUE,PWM_PERIOD,0, FALSE);	//1.CH1N
	}
}


/** @brief	fonction qui applique le rapport cyclique demand� vers le pont de puissance qui pilote le moteur.
 * @func	void MOTOR_set_duty(uint16_t duty, motor_e motor)
 * @param	duty  : le rapport cyclique a appliquer, de -100 � +100.
 * @param	motor : MOTOR1, MOTOR2, MOTOR3 ou MOTOR4
 * @post	Pour un rapport duty n�gatif, une PWM sera appliqu�e sur le canal n�gatif, et un 0 sera impos� sur le canal positif.
 * @post	Pour un rapport duty positif, une PWM sera appliqu�e sur le canal positif, et un 0 sera impos� sur le canal n�gatif.
 */
void MOTOR_set_duty(int16_t duty, motor_e motor)
{
	bool_e negative;					//Indique si le rapport cyclique demand� est n�gatif.
	uint32_t channel;
	timer_id_e timer_id;
	TIM_HandleTypeDef * handler = NULL;
	timer_id_e timer_id_stop;
	TIM_HandleTypeDef * handler_stop = NULL;
	negative = (duty < 0)?TRUE:FALSE;

	//Ecretage... Le rapport cyclique est exprim� dans la m�me unit� que la PWM_PERIOD, il ne peut donc pas �tre plus grand !
	if(duty > 100)
		duty = 100;
	else if(duty < -100)
		duty = -100;

	/* Configuration GPIO et remappings
	 *
	 * Pour chaque moteur, on dispose de deux signaux PWM.
	 * Selon le sens demand�, d�marre et on arr�te les broches correspondantes.
	 */

	switch(motor)
	{
		case MOTOR1:
			channel						= TIM_CHANNEL_1;
			timer_id 					= TIMER1_ID;
			handler 					= TIMER_get_phandler(timer_id);
			duty 						= (negative)?(-duty):duty;
			if(negative)
			{
				HAL_TIM_PWM_Stop(handler, channel);
				HAL_TIMEx_PWMN_Start(handler, channel);
			}
			else
			{
				HAL_TIMEx_PWMN_Stop(handler, channel);
				HAL_TIM_PWM_Start(handler, channel);
			}
			break;
		case MOTOR2:
			channel						= TIM_CHANNEL_2;
			timer_id 					= TIMER1_ID;
			handler 					= TIMER_get_phandler(timer_id);
			duty 						= (negative)?(-duty):duty;
			if(negative)
			{
				HAL_TIM_PWM_Stop(handler, channel);
				HAL_TIMEx_PWMN_Start(handler, channel);
			}
			else
			{
				HAL_TIMEx_PWMN_Stop(handler, channel);
				HAL_TIM_PWM_Start(handler, channel);
			}
			break;
		case MOTOR3:
			channel						= TIM_CHANNEL_3;
			timer_id 					= TIMER1_ID;
			handler 					= TIMER_get_phandler(timer_id);
			duty 						= (negative)?(-duty):duty;
			if(negative)
			{
				HAL_TIM_PWM_Stop(handler, channel);
				HAL_TIMEx_PWMN_Start(handler, channel);
			}
			else
			{
				HAL_TIMEx_PWMN_Stop(handler, channel);
				HAL_TIM_PWM_Start(handler, channel);
			}
			break;
		case MOTOR4:
			channel						= TIM_CHANNEL_4;
			duty 						= (negative)?(-duty):duty;
			timer_id_stop 				= (negative)?TIMER1_ID:TIMER2_ID;
			handler_stop				= TIMER_get_phandler(timer_id_stop);
			timer_id 					= (negative)?TIMER2_ID:TIMER1_ID;
			handler 					= TIMER_get_phandler(timer_id);
			if(negative)
			{
				HAL_TIM_PWM_Stop(handler_stop, channel);
				HAL_TIM_PWM_Start(handler, channel);
			}
			else
			{
				HAL_TIM_PWM_Stop(handler_stop, channel);
				HAL_TIM_PWM_Start(handler, channel);
			}
			break;
		default:
			return;
			break;
	}

	PWM_set_duty(timer_id, channel, negative, (uint32_t)duty);
}

#endif
