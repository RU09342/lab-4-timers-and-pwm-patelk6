# Hardware PWM
Hardware PWM is much simpler to implement than software PWM. Each board has a set number of PWM pins that will automatically
output a PWM signal (based on chosen parameters). At this point, we make use of them.

## How it is implemented
In order to implement Hardware PWM, we must first check the datasheet, to find out which pins can output a PWM signal.
Once we have this information, we can use that pins associated timer module to generate our desired wave. 
Now that you have done the software version of PWM, now it is time to start leveraging the other features of these Timer Modules.

## Task
You need to replicate the same behavior as in the software PWM, only using the Timer Modules ability to directly output to a GPIO Pin instead of managing them in software. 

### Hints 
Read up on the P1SEL registers as well as look at the Timer modules ability to multiplex.

## Extra Work
### Using ACLK
Some of these microprocessors have a built in ACLK which is extremely slow compared to your up to 25MHz available on some of them. What is the overall impact on the system when using this clock? Can you actually use your PWM code with a clock that slow?

### Ultra Low Power
Using a combination of ACLK, Low Power Modes, and any other means you may deem necessary, optimize this PWM code to run at 50% duty cycle with a LED on the MSP430FR5994. In particular, time how long your code can run on the fully charged super capacitor. You do not need to worry about the button control in this case, and you will probably want to disable all the GPIO that you are not using (nudge, nudge, hint, hint).