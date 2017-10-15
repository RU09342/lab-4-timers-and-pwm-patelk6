#include <msp430G2553.h>
unsigned int count=0;
int main(void)
{

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= (BIT0);           // Set P1.0 to output direction

  P1DIR &= ~BIT3;               // button is an input
  P1OUT |= BIT3;                // pull-up resistor
  P1REN |= BIT3;                // resistor enabled

  P1IE |= BIT3;         // P1.3 interrupt enabled
  P1IFG &= ~BIT3;       // P1.3 IFG cleared



  __bis_SR_register(LPM0_bits + GIE);
  for(;;);





}


#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
     P1OUT ^= BIT0;
    P1IE &= ~BIT3;
   count++;

    CCR0=680;
    CCTL0 |= CCIE;
    TA0CTL|=TASSEL_1+MC_1+ID_3+TACLR;





  //  __bic_SR_register_on_exit(LPM0_bits);


     // P1.3 IFG cleared

}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
    TA0CTL |= MC_0;
    CCTL0 &= ~CCIE;



    P1IFG &= ~BIT3;
    P1IE |= BIT3;
    P1OUT |= BIT3;

 //   __bic_SR_register_on_exit(LPM0_bits);
}



