#include <msp430FR6989.h>
unsigned int delay=0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;


       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //choosing pin 2.0 for hardware pwm
       P3SEL1 |= BIT3;
       P3DIR|= BIT3;

       TA1CCTL1 += OUTMOD_7;
       TA1CTL = TASSEL_2 + MC_1;
       TA1CCR0 = 1000;
       TA1CCR1 = 500;



       P1DIR &= ~BIT1;
       P1OUT |= BIT1;
       P1REN |= BIT1;
       P1IE |= BIT1;
       P1IFG &=~BIT1;




      __enable_interrupt();
     //  __no_operation();
       while(1){

       }
   }
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

    __delay_cycles(10000);

    TA1CCR1+=100;
   if(TA1CCR1>1000){
       TA1CCR1=100;
   }
    P1IFG &=~BIT1;


}




