#include <stdio.h>
#include <unistd.h>
#include "galileogpio.h"

int main() {
	int value;
	int retorno = enableAnalog(A5);
	printf("enableAnalog retornou %d\n",retorno);
	initPWM(PWM3,1*MS,500*US);
	while(1) {
		value = getAnalog(A5);
		printf("%d\n",value);
		setDutyCyclePWM(PWM3,(value*1*MS)/4096);
		usleep(1);
	}	
	return 0;
}