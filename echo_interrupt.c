#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define BUTTON_PIN 0

void isr()
{
	putchar('B');
}

void task(){
	unsigned long i,j,k;
	for(int i=0; i<400000000; i++);
}

int main()
{
	int i=0;
	wiringPiSetup();
	pinMode(0, INPUT);
	pullUpDnControl(BUTTON_PIN, PUD_UP);

	wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &isr);

	while(1) {
		task();
	}
	return 0;
}
