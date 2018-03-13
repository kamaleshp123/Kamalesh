#include <stdint.h>
#include <lpc13xx.h>
#include <iocon.h>
#include <clocks.h>
#include <ct16b0.h>
#include <io.h>

typedef enum
{
	CT16B0_CTR_RUN_PCLK,
	CT16B0_CTR_RUN_RISE_EDGE,
	CT16B0_CTR_RUN_FALL_EDGE,
	CT16B0_CTR_RUN_BOTH_EDGE
}ct16b0_ctr_run_t;



#define Update_CT16B0_Prescalar(value)	LPC_TMR16B0->PR = value

#define Disable_CT16B0_Counter()				LPC_TMR16B0->TCR &= ~(1<<0)
#define Enable_CT16B0_Counter()				  LPC_TMR16B0->TCR |= (1<<0)

#define Deassert_CT16B0_Reset()					LPC_TMR16B0->TCR &= ~(1<<1)
#define Assert_CT16B0_Reset()           LPC_TMR16B0->TCR |= (1<<1)

#define CT16B0_CTM_BIT_MASK	(1<<1) | (1<<0)
#define Update_CT16B0_CTM(option)				LPC_TMR16B0->CTCR = 	(LPC_TMR16B0->CTCR & ~(CT16B0_CTM_BIT_MASK)) | (option) 

#define Set_CT16B0_Cap_Fall_Edge()			LPC_TMR16B0->CCR |= (1<<1)
#define Set_CT16B0_Cap_Rise_Edge()			LPC_TMR16B0->CCR |= (1<<0)

static void Set_CT16B0_Base_Config(void)
{
	// IOCON call in Init_Peripherals()
	Enable_CT16B0_Clock();
}	

static void Set_CT16B0_Core_Config(void)
{
	Disable_CT16B0_Counter();
	Update_CT16B0_Counter(0);
	Update_CT16B0_CTM((ct16b0_ctr_run_t)CT16B0_CTR_RUN_FALL_EDGE);
	Set_CT16B0_Cap_Fall_Edge();
	Enable_CT16B0_Counter();
	Deassert_CT16B0_Reset();
}	

void Init_CT16B0(void)
{
	Set_CT16B0_Base_Config();
	Set_CT16B0_Core_Config();
}	
