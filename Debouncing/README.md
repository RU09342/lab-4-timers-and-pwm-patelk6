# Software Debouncing
Button debouncing is tackled in this lab. Specifically, we look at software debouncing. It is possible to debounce a button
using hardware, such as capacitors, but that can sometimes be seen as inadvisable, as you would need to slap in 
capacitors to a structure that may be all finished and ready for mass fabrication. As a result, we can use timer modules 
to debounce a button, by essentially simulating a capacitor.

##How it works
When we use a button, it does not immediately jump to high once we press it. Instead, there could be many different
oscillations, as the button is pressed and depressed multiple times before finally stabilising. This is due to the fact
that buttons are a mechanical object. They are not perfect. The basic idea behind debouncing a button is to eliminate
all of the oscillation that is present. In hardware, we would use a capacitor, as it would act as a filter, to filter out
the noise caused by the oscillation of the button. In software, we use the built in timer modules. Essentially, we 
let the button be activated. Then, we disable the button to rpevent it from being activated again for the near future.
We then re enable the button once our timer is up (once the button has stabilised).

##Implementing
Implementing this code is simple. You simply take the main.c file that you want to work with, put it into your project 
folder, making sure that the appropriate processor is linked, and run it.

