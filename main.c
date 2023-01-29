#include "lib/include.h"


/* EXPERIMENTO 2
   Usando el modulo 0 de PWM con una frecuencia de reloj del sistema de 20,000,000 Hz
   junto con el generador 0,1,2  habilitar alguno de los pwm's asociados y obtener un PWM
   cuya frecuencia sea de 50Hz con tres potenciometros variar el ciclo de trabajo para 
   controlar la posición de tres servos sg90 o otros 
*/
int main(void)
{
    uint16_t Result[2];
    uint16_t duty[2];
    Configurar_PLL(F20MHZ); 
    Configura_Reg_PWM0(50);  
    Configura_Reg_ADC0();

    while (1)
    {  
        ADC0_InSeq2(Result,duty);

        PWM0->_0_CMPB =duty[0]; //PE2 - PF1
        PWM0->_1_CMPA =duty[1]; //PE1 - PF2
        PWM0->_2_CMPA =duty[2]; //PE5 - PG0
    }
}
