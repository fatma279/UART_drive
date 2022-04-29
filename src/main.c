
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"

int main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA);		/* Enable PORTA */
	MRCC_voidEnableClock(APB2, USART1);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output push pull w max speed 50 MHz */
	GPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_PP);
	/* Setting A10:RX pin as input floating */
	GPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	GPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();

	u8 x;

	while(1)
	{
		MUSART1_voidTransmit("56");
		x = MUSART1_u8Receive();
		if(x == '6')
		{
			GPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
		}
		if(x == '7')
		{
			GPIO_voidSetPinValue(GPIOA,PIN0,LOW);
		}
	}

	return 0;
}
