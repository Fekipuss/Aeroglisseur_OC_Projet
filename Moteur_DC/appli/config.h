/*
 * config.h
 *
 *  Created on: 31 mars 2016
 *      Author: Nirgal
 */

#ifndef CONFIG_H_
#define CONFIG_H_

//Choix de la cible utilis�e.
#define NUCLEO	0
#define BLUEPILL 1

//_______________________________________________________
//Configuration des broches utilis�es...
//Ces macros permettent d'utiliser dans le code des noms explicites (LED_GREEN, ...)
#if NUCLEO
	#define LED_GREEN	GPIOA, GPIO_PIN_5
	#define BLUE_BUTTON	GPIOC, GPIO_PIN_13
	#if BLUEPILL
		#error "Vous ne pouvez pas d�finir � la fois NUCLEO et BLUEPILL !"
	#endif
#endif
#if BLUEPILL
	#define LED_GREEN	GPIOC, GPIO_PIN_13
	#define BLUE_BUTTON	GPIOA, GPIO_PIN_15		//Pas de bouton sur la bluepill, choisissez le port souhait� si vous en reliez un.
#endif

//Choisir les broches pour l'UART1, parmi ces deux possibilit�s :
#define UART1_ON_PB6_PB7
//#define UART1_ON_PA9_PA10

//Choisir les broches pour l'UART2, parmi ces deux possibilit�s :
#define UART2_ON_PA2_PA3
//#define UART2_ON_PD5_PD6

//Choisir les broches pour l'UART3, parmi ces deux possibilit�s :
#define UART3_ON_PB10_PB11
//#define UART3_ON_PD8_PD9

//_______________________________________________________


//Ci dessous, les defines permettant d'activer les modules de la librairie.
//Attention, s'ils sont tous activ�s, le code compil� est trop volumineux pour rentrer dans la m�moire de 64kio du STM32F103C8T6 la Bluepill.
//Le STM32F103RBT6 de la carte Nucleo dispose quant � lui d'une m�moire de 128kio de flash.

#define USE_SCREEN_TFT_ILI9341		0	//Ecran TFT 2.4
	#if USE_SCREEN_TFT_ILI9341
		#define USE_XPT2046			1	//Tactile

		#define USE_FONT11x18		0
		#define USE_FONT7x10		1
		#define USE_FONT16x26		0
	#endif


#define USE_SCREEN_LCD2X16			0	//Ecran LCD 2x16

#define USE_TFT_PCD8544				0	//Ecran TFT Nokia

//Carte capteur IKS01A1 :
#define USE_SENSOR_HTS221		0//Humidit� et temp�rature
#define USE_SENSOR_LPS25HB		0//Pression (et temp�rature)
#define USE_SENSOR_LSM6DS0		0//Acc�l�rom�tre et Gyroscope
#define USE_SENSOR_LIS3MDL		0//Magnetometre

//Autres capteurs :
#define USE_SENSOR_LSM6DS3		0//Acc�l�rom�tre et Gyroscope
#define USE_SENSOR_LPS22HB		0//Pression (et temp�rature)
#define USE_MLX90614			0	//Capteur de temp�rature sans contact
#define USE_MPU6050				0//Acc�l�rom�tre et Gyroscope

#define USE_MATRIX_KEYBOARD		0
#define USE_MATRIX_LED			0
#define USE_CAPACITIVE_KEYBOARD	0
#define USE_MATRIX_LED_32_32	0
#define USE_FINGERPRINT			0

#define USE_MCP23S17			0//Port expander I/O
#define USE_APDS9960			0	//Capteur de gestes, de couleur, de luminosit� ambiante
#define USE_BH1750FVI			0	//Capteur de luminosit� ambiante
#define USE_BMP180				0	//Capteur de pression
#define USE_MOTOR_DC			1
#define USE_RTC					0
#define USE_PWM					1
#define USE_ESP8266				0//Module Wifi
#define USE_NFC03A1				0

#define USE_SD_CARD				0	//Utilisation d'une carte SD pour lire/�crire des fichiers

#define USE_ADC					0

#define USE_BSP_TIMER			1 //Utilisation de stm32f1_timer.c/h

//Liste des modules utilisant le p�riph�rique I2C
#if USE_MLX90614 || USE_MPU6050	|| USE_APDS9960	 || USE_BH1750FVI || USE_BMP180
	#define USE_I2C				1
#endif

//Liste des modules utilisant le p�riph�rique SPI
#if USE_SCREEN_TFT_ILI9341	|| USE_SD_CARD
	#define USE_SPI				1
#endif

#endif /* CONFIG_H_ */
