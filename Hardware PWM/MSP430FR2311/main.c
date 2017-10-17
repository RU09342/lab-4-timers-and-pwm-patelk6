#include <msp430FR2311.h>
unsigned int delay=0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;


       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //choosing pin 2.0 for hardware pwm
       P2SEL0 |= BIT0;
       P2DIR|= BIT0;
		//set up timer
       TB1CCTL1 |=  OUTMOD_7;
       TB1CTL = TBSSEL_2 + MC_1;
       TB1CCR0 = 1000;
       TB1CCR1 = 10;


		//set up button
       P1DIR &= ~BIT1;
       P1OUT |= BIT1;
       P1REN |= BIT1;


       while(1){

       }
   }
#pragma vector = TIMER4_A1_VECTOR
__interrupt void clockOverFlow(void){

	P2OUT ^= BIT0;

}




