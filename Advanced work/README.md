# Power/Energy Analysis
EnergyTrace is a powerful tool that is available in Code Composer Studio. This tool allows us to examine the amount of power
and energy being used by the MCU when running programs. When designing embedded systems, it is very important to 
understand the power draw that is used to run your code. Just like in software engineering, one must take into account
the amount of memory and processing power required by your code. If your code takes 20 hours and 15 GB of RAM to sort an
array of size 10, there is an issue. Similarily, in the world of embedded systems, if you require 15 kW of power 
just to toggle an LED, there is a good chance you will soon be unemployed. There are a multitude of factors that can affect
the power usage of your processor. In this case, we will examine the effects of using different speed clocks, predividers,
and different duty cycles.

## Clock Speed
First, the effect of using different clock speeds is examined. The following two images are captured
concerning the energy and power usage.

![Alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_SM.PNG "Power of SMClk")

SMClk runs at 1MHz. We can see that we use about 5.73 to 6.09 mW of power any given time.

![Alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_A.png "Power of SMClk")

AClk runs at 32 kHz. As we can see from the preceeding image, we use about 2.4 to 11.4 mW of power at any given time.

### Differences
One interesting result is the sharp increase in power usage between the AClk and SMClk. The AClk, despite being of lower 
frequency, has a higher power draw than the SMClk, which runs at over 10x the frequency. This would lead me to the conclusion
that the driving force behind MClk is much more power efficient than the driving force behind AClk, with the exception
of lower minimum power draws.

## Predividers
Next, we examine the use of predividers. In this instance, we examine the power draw of SMClk with and without a predivider.
Power draw of SMClk without any predivider.

![Alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_SM.png "Power of SMClk")

Power draw of SMClk with an 8 predivider.

![Alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_SM_8.png "Power of SMClk with 8 divider")

We see a similar trend between regular SMClk and SMClk with 8 divider that we saw previously with SMClk vs AClk.
Using the 8 divider, we get a larger spread in the power draw when using the 8 divider. Another worthy observation
is that the power draw seems more consistent when using the 8 divider. This would imply that is uses more power 
to divide the clock signal, rather than to just let it run without.

## Duty Cycle
Finally, we examine the different power draws of various duty cycles. In this instance, we compare the 
power draw from a 50% duty cycle of SMClk, and a 100% duty of SMClk.

![alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_SM.PNG "Power of SMClk")

![Alt text](https://github.com/RU09342/lab-4-timers-and-pwm-patelk6/blob/master/Advanced%20work/pictures/power_SM_100p.png "Power of SMClk")

As can be seen in the images, duty cycle almost has a linear effect on the power draw. When the duty cycle is doubled,
the power is nearly doubled as well. This is perhaps the one result that came out as expected, as with a higher duty cycle,
the LED will be on more than compared to a duty cycle of 50%.

