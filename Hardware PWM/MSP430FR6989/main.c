#include <msp430FR6989.h>
unsigned int delay=0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;


       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //choosing pin 3.3 for hardware pwm
       P3SEL1 |= BIT3;
       P3DIR|= BIT3;
		//set up timer
       TA1CCTL1 += OUTMOD_7;
       TA1CTL = TASSEL_2 + MC_1;
       TA1CCR0 = 1000;
       TA1CCR1 = 100;


		//set up button
       P1DIR &= ~BIT1;
       P1OUT |= BIT1;
       P1REN |= BIT1;




       __bis_SR_register(LPM0_bits + GIE);

       while(1){

       }
   }
#pragma vector = TIMER0_A0_VECTOR
__interrupt void clockOverFlow(void){

    P1OUT^=BIT0;

}




