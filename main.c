#include "lib/include.h"


/* EXPERIMENTO 2
   Usando el modulo 0 de PWM con una frecuencia de reloj del sistema de 20,000,000 Hz
   junto con el generador 0,1,2  habilitar alguno de los pwm's asociados y obtener un PWM
   cuya frecuencia sea de 50Hz con tres potenciometros variar el ciclo de trabajo para 
   controlar la posición de tres servos sg90 o otros 
*/
int main(void)
{

    Configurar_PLL(F20MHZ); 
    Configura_Reg_PWM0(50);  

    while (1)
    {  
        
    }
}
