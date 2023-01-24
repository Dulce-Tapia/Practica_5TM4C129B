#include "lib/include.h"

extern void Configura_Reg_PWM0(uint16_t freq)
{
    // //Habilitar el reloj de modulo pag 398 
    SYSCTL->RCGCPWM |= (1<<0); //Nota *la tiva grande solo tiene 1)
    // Habilitar el puerto F y G  pag 383
    SYSCTL->RCGCGPIO |= (1<<6)|(1<<5);
    // Habilitar función alternativa pag 770
    GPIOG_AHB->AFSEL |= (1<<0); // PG0
    GPIOF_AHB->AFSEL |= (1<<1)|(1<<2); //PF1 y PF2 
    // Habilitar la salida 
    GPIOG_AHB->DIR = (1<<0); //PG0
    GPIOF_AHB->DIR = (1<<1)|(1<<2);//PF1 y PF2 
    //Indicar funcion alternativa (PWM) (PCTL) p. 689, 1808
    //6 indica que es PWM
    GPIOG_AHB->PCTL |= (GPIOG_AHB->PCTL&0xFFFFFFF0) | 0x00000006;
    GPIOF_AHB->PCTL |= (GPIOF_AHB->PCTL&0xFFFFF00F) | 0x00000660;
    //pin digital pag 682
    GPIOG_AHB->DEN |= (1<<0); 
    GPIOF_AHB->DEN |= (1<<1)|(1<<2);
    //habilitar divisor (RCC) p. 254 Enable o Disable Divisor  Pag 1747
    PWM0->CC = (1<<8)|(0<<2)|(1<<1)|(0<<0);    
    //deshabilitar generador (CTL) p. 1266, 1233
    PWM0->_2_CTL = (0<<0);
    PWM0->_0_CTL = (0<<0);
    PWM0->_1_CTL = (0<<0);
    //registro de las acciones del pwm (modo de configuración) p. 1285
     //pag 1248 dice con que comparador trabajan
    PWM0->_0_GENB = 0x0000080C;         
    PWM0->_2_GENA = 0x0000008C;
    PWM0->_1_GENA = 0x0000008C;
    // Cargo el valor cuentas = fclk/fpwm  
    PWM0->_2_LOAD = 50000;
    PWM0->_1_LOAD = 50000;
    PWM0->_0_LOAD = 50000;
    PWM0->_2_CMPA = 35000;     //Ciclo de trabajo Nota *Regla de 3
    PWM0->_1_CMPA = 35000;
    PWM0->_0_CMPB = 35000;
    // Se activa el generador 0,1,2
    PWM0->_2_CTL = (1<<0);
    PWM0->_1_CTL = (1<<0);
    PWM0->_0_CTL = (1<<0);
    // habilitar el PWM3,PWM2,PWM4  pag 1687
    PWM0->ENABLE = (1<<1)|(1<<2)|(1<<4);         
}