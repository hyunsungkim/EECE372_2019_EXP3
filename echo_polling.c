#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define BUTTON_PIN 0

void task()
{
	int i;
	for(i=0; i<4000000; i++);
}

int main()
{
	int curButtonState;
	int preButtonState = 0;

	wiringPiSetup();
	pinMode(BUTTON_PIN, INPUT);
	pullUpDnControl(BUTTON_PIN, PUD_UP);

	while(1) {
		curButtonState = digitalRead(BUTTON_PIN);
		if(curButtonState == 0 && preButtonState == 1) {
			printf("Button Pushed\r\n");
		}
		preButtonState = curButtonState;
	}
	return 0;
}
