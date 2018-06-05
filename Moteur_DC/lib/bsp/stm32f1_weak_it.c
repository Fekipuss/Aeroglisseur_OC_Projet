/*
 * stm32f1_weak_it.c
 *
 *  Created on: 29 mars 2018
 *      Author: Nirgal
 */
#include "stm32f1xx_hal.h"
#include "stm32f1_sys.h"

const char * msg = "IT not handled in user code : ";

__weak void NMI_Handler(void)
{
	dump_printf("%s%s", " NMI_Handler");
	while(1);
}

__weak void HardFault_Handler(void)
{
	dump_printf("%s%s", msg, " HardFault_Handler");
	while(1);
}

__weak void MemManage_Handler(void)
{
	dump_printf("%s%s", " MemManage_Handler");
	while(1);
}

__weak void BusFault_Handler(void)
{
	dump_printf("%s%s", " BusFault_Handler");
	while(1);
}

__weak void UsageFault_Handler(void)
{
	dump_printf("%s%s", " UsageFault_Handler");
	while(1);
}

__weak void SVC_Handler(void)
{
	dump_printf("%s%s", " SVC_Handler");
	while(1);
}

__weak void DebugMon_Handler(void)
{
	dump_printf("%s%s", " DebugMon_Handler");
	while(1);
}

__weak void PendSV_Handler(void)
{
	dump_printf("%s%s", " PendSV_Handler");
	while(1);
}

__weak void SysTick_Handler(void)
{
	dump_printf("%s%s", " SysTick_Handler");
	while(1);
}

__weak void WWDG_IRQHandler(void)
{
	dump_printf("%s%s", " WWDG_IRQHandler");
	while(1);
}

__weak void PVD_IRQHandler(void)
{
	dump_printf("%s%s", " PVD_IRQHandler");
	while(1);
}

__weak void TAMPER_IRQHandler(void)
{
	dump_printf("%s%s", " TAMPER_IRQHandler");
	while(1);
}

__weak void RTC_IRQHandler(void)
{
	dump_printf("%s%s", " RTC_IRQHandler");
	while(1);
}

__weak void FLASH_IRQHandler(void)
{
	dump_printf("%s%s", " FLASH_IRQHandler");
	while(1);
}

__weak void RCC_IRQHandler(void)
{
	dump_printf("%s%s", " RCC_IRQHandler");
	while(1);
}

__weak void EXTI0_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI0_IRQHandler");
	while(1);
}

__weak void EXTI1_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI1_IRQHandler");
	while(1);
}

__weak void EXTI2_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI2_IRQHandler");
	while(1);
}

__weak void EXTI3_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI3_IRQHandler");
	while(1);
}

__weak void EXTI4_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI4_IRQHandler");
	while(1);
}

__weak void DMA1_Channel1_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel1_IRQHandler");
	while(1);
}

__weak void DMA1_Channel2_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel2_IRQHandler");
	while(1);
}

__weak void DMA1_Channel3_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel3_IRQHandler");
	while(1);
}

__weak void DMA1_Channel4_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel4_IRQHandler");
	while(1);
}

__weak void DMA1_Channel5_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel5_IRQHandler");
	while(1);
}

__weak void DMA1_Channel6_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel6_IRQHandler");
	while(1);
}

__weak void DMA1_Channel7_IRQHandler(void)
{
	dump_printf("%s%s", " DMA1_Channel7_IRQHandler");
	while(1);
}

__weak void ADC1_2_IRQHandler(void)
{
	dump_printf("%s%s", " ADC1_2_IRQHandler");
	while(1);
}

__weak void USB_HP_CAN1_TX_IRQHandler(void)
{
	dump_printf("%s%s", " USB_HP_CAN1_TX_IRQHandler");
	while(1);
}

__weak void USB_LP_CAN1_RX0_IRQHandler(void)
{
	dump_printf("%s%s", " USB_LP_CAN1_RX0_IRQHandler");
	while(1);
}

__weak void CAN1_RX1_IRQHandler(void)
{
	dump_printf("%s%s", " CAN1_RX1_IRQHandler");
	while(1);
}

__weak void CAN1_SCE_IRQHandler(void)
{
	dump_printf("%s%s", " CAN1_SCE_IRQHandler");
	while(1);
}

__weak void EXTI9_5_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI9_5_IRQHandler");
	while(1);
}

__weak void TIM1_BRK_IRQHandler(void)
{
	dump_printf("%s%s", " TIM1_BRK_IRQHandler");
	while(1);
}

__weak void TIM1_UP_IRQHandler(void)
{
	dump_printf("%s%s", " TIM1_UP_IRQHandler");
	while(1);
}

__weak void TIM1_TRG_COM_IRQHandler(void)
{
	dump_printf("%s%s", " TIM1_TRG_COM_IRQHandler");
	while(1);
}

__weak void TIM1_CC_IRQHandler(void)
{
	dump_printf("%s%s", " TIM1_CC_IRQHandler");
	while(1);
}

__weak void TIM2_IRQHandler(void)
{
	dump_printf("%s%s", " TIM2_IRQHandler");
	while(1);
}

__weak void TIM3_IRQHandler(void)
{
	dump_printf("%s%s", " TIM3_IRQHandler");
	while(1);
}

__weak void TIM4_IRQHandler(void)
{
	dump_printf("%s%s", " TIM4_IRQHandler");
	while(1);
}

__weak void I2C1_EV_IRQHandler(void)
{
	dump_printf("%s%s", " I2C1_EV_IRQHandler");
	while(1);
}

__weak void I2C1_ER_IRQHandler(void)
{
	dump_printf("%s%s", " I2C1_ER_IRQHandler");
	while(1);
}

__weak void I2C2_EV_IRQHandler(void)
{
	dump_printf("%s%s", " I2C2_EV_IRQHandler");
	while(1);
}

__weak void I2C2_ER_IRQHandler(void)
{
	dump_printf("%s%s", " I2C2_ER_IRQHandler");
	while(1);
}

__weak void SPI1_IRQHandler(void)
{
	dump_printf("%s%s", " SPI1_IRQHandler");
	while(1);
}

__weak void SPI2_IRQHandler(void)
{
	dump_printf("%s%s", " SPI2_IRQHandler");
	while(1);
}

__weak void USART1_IRQHandler(void)
{
	dump_printf("%s%s", " USART1_IRQHandler");
	while(1);
}

__weak void USART2_IRQHandler(void)
{
	dump_printf("%s%s", " USART2_IRQHandler");
	while(1);
}

__weak void USART3_IRQHandler(void)
{
	dump_printf("%s%s", " USART3_IRQHandler");
	while(1);
}

__weak void EXTI15_10_IRQHandler(void)
{
	dump_printf("%s%s", " EXTI15_10_IRQHandler");
	while(1);
}

__weak void RTC_Alarm_IRQHandler(void)
{
	dump_printf("%s%s", " RTC_Alarm_IRQHandler");
	while(1);
}

__weak void USBWakeUp_IRQHandler(void)
{
	dump_printf("%s%s", " USBWakeUp_IRQHandler");
}

