#include <msp430FR2311.h>
unsigned int count=0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;


       P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
       P1DIR |= BIT0;                          // Set P1.0 to output direction

       //choosing pin 2.0 for hardware pwm
       P2SEL1 |= BIT0;
       P2DIR|= BIT0;





       P1DIR &= ~BIT1;
       P1OUT |= BIT1;
       P1REN |= BIT1;
       P1IE |=BIT1;
       P1IFG&=~BIT1;

    //   TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
     //  TA0CCR0 = 62500;
     //  TA0CTL = TASSEL_1 + MC_1 + ID_3;         // SMCLK, upmode, clear TAR



       __bis_SR_register(LPM0_bits + GIE);
     //  __no_operation();
       __enable_interrupt();
       while(1){

       }
   }

#pragma vector = PORT5_VECTOR
__interrupt void buttonPress(void)
{
     P1OUT ^= BIT0;
    P1IE &= ~BIT1;
   count++;

    TA0CCR0=680;
    TA0CCTL0 |= CCIE;
    TA0CTL|=TASSEL_1+MC_1+ID_3+TACLR;

}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
    TA0CTL |= MC_0;
    TA0CCTL0 &= ~CCIE;


    P1IFG &= ~BIT1;
    P1IE |= BIT1;
}




