#include <msp430G2553.h>
 int delay =0;
int main(void)
{

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= (BIT6);           // Set P1.0 to output direction
  P1SEL |= BIT6;

  P1REN |= BIT3;                   // Enable internal pull-up/down resistors
    P1OUT |= BIT3;                   //Select pull-up mode for P1.3
    P1IE |= BIT3;                       // P1.3 interrupt enabled
    P1IES |= BIT3;                     // P1.3 Hi/lo edge
    P1IFG &= ~BIT3;

  TA0CCTL1 |= OUTMOD_7;
  TA0CCR0 |= 1000;
  TA0CCR1 |= 500;
  TA0CTL |= TASSEL_2 + MC_1;

  __bis_SR_register(LPM1_bits + GIE);
  while(1){

  }


}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

    __delay_cycles(10000);

    TA0CCR1+=100;
   if(TA0CCR1>1000){
       TA0CCR1=100;
   }
    P1IFG &=~BIT3;


}






