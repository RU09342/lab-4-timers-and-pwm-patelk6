#include <msp430FR6989.h>
unsigned int count=0;
int main(void)
{

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  PM5CTL0 &= ~LOCKLPM5;

  P1DIR |= (BIT0);           // Set P1.0 to output direction

  P1DIR &= ~BIT1;               // button is an input
  P1OUT |= BIT1;                // pull-up resistor
  P1REN |= BIT1;                // resistor enabled

  P1IE |= BIT1;         // P1.3 interrupt enabled
  P1IFG &= ~BIT1;       // P1.3 IFG cleared



  __bis_SR_register(LPM0_bits + GIE);
  for(;;);





}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
     P1OUT ^= BIT0;
    P1IE &= ~BIT1;
   count++;

    TA0CCR0=1360;
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
    P1OUT |= BIT1;

 //   __bic_SR_register_on_exit(LPM0_bits);
}








