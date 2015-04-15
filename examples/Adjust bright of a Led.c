#include <stdio.h>
#include <unistd.h>
#include "galileogpio.h"

int main() {
	int value;
	// Enable the Analog Port A0
	enableAnalog(A0);
	// Init PWM3 with 1ms of period and 500us of duty cycle
	initPWM(PWM3,1*MS,500*US);

	while(1) {
		// Get the analog voltage of the potentiometer
		value = getAnalog(A5);
		// Adjust the duty cycle proportionally to the voltage, to adjust
		// the bright of the LED
		setDutyCyclePWM(PWM3,(value*1*MS)/4096);
		// Sleep for 1 us
		usleep(1);
	}	
	return 0;
}