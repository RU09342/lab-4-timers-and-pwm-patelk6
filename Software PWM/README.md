# Software PWM
In this lab, we fabricate a PWM module using pure software. In order to do this, we make use of the timer modules
in order to simulate a PWM wave. Essentially, we need to manually set and reset the status of the pin at 
certain times.

## How it works
We use two CCR registers, with different interrupt routines on each. On one, we will reset the status of the pin,
and on the other, we will set the status of the pin, thus simulating exactly what the hardware PWM will do.
In addition, we use a button to control the duty cycle. The processor will default to a duty cycle of 50%. Each 
button press will increase the duty cycle by 10%, until it reaches 100%, at which point it will reset back to 10.

###Implementing
Implementing this code is simple. You simply take the main.c file that you want to work with, put it into your project 
folder, making sure that the appropriate processor is linked, and run it.
