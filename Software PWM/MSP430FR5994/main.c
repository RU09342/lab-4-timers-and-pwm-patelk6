#include <msp430FR5994.h>
unsigned int delay=0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;


       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //choosing pin 5.7 for hardware pwm
       P5SEL1 |= BIT7;
       P5DIR|= BIT7;
       //Setting up timer
       TA4CCTL1 += OUTMOD_7;
       TA4CTL = TASSEL_2 + MC_1;
       TA4CCR0 = 1000;
       TA4CCR1 = 500;


		//Setting up button
       P5DIR &= ~BIT6;
       P5OUT |= BIT6;
       P5REN |= BIT6;
       P5IE |=BIT6;





       __enable_interrupt();
       while(1){

       }
   }
#pragma vector = TIMER0_A0_VECTOR
__interrupt void clockOverFlow(void){

    P1OUT^=BIT0;

}
#pragma vector = PORT5_VECTOR
__interrupt void buttonPess(){
    TA4CCR1+=100;
    if(TA4CCR1>1000){
        TA4CCR1=100;
    }
    P5IFG&=~BIT6;
}




