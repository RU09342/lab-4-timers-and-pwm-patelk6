#include <msp430FR2311.h>
 int delay =0;
int main(void)
{

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  PM5CTL0 &= ~LOCKLPM5;

  P2DIR |= (BIT0);           // Set P1.0 to output direction
  P2SEL0 |= BIT0;

  P1REN |= BIT1;                   // Enable internal pull-up/down resistors
    P1OUT |= BIT1;                   //Select pull-up mode for P1.3
    P1IE |= BIT1;                       // P1.3 interrupt enabled
    P1IES |= BIT1;                     // P1.3 Hi/lo edge
    P1IFG &= ~BIT1;
  //Setting up timer
  TB1CCTL1 |= OUTMOD_7;
  TB1CCR0 |= 1000;
  TB1CCR1 |= 500;
  TB1CTL |= TBSSEL_2 + MC_1 + ID_3;

  __bis_SR_register(LPM0_bits + GIE);
  while(1){

  }


}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

    __delay_cycles(10000);

    TB1CCR1+=100;
   if(TB1CCR1>1000){
       TB1CCR1=100;
   }
    P1IFG &=~BIT1;


}






