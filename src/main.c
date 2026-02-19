#include <stdio.h>
#include <header1.h>
int main()
{
int x =1;
setupGPIO();
while (1)
{
	switch(x) {
		case 1:
		if(!(checkBot(TST))) {
			x=2;
		}
		setLED(GREEN_LED,ON);
		setLED(RED_LED,ON);
		setLED(YELLOW_LED,ON);
		delay(1000);

		setLED(RED_LED,OFF);
		setLED(YELLOW_LED,OFF);
		delay(1000);
		break;
		
		case 2:

			if(!(checkBot(FLA)) && checkBot(TST)) {
				x =1;
			} else if ((checkBot(FLA))) {
				x = 3;
			}
			setLED(GREEN_LED,ON);
			setLED(RED_LED,OFF);
			setLED(YELLOW_LED,OFF);
			break;

		case 3:
			if((!(checkBot(FLA))) && (!(checkBot(OLA)))) {
				x=2;
			} else if(checkBot(OLA)) {
				x=5;
			} else if ((!(checkBot(OLA)))&& checkBot(FLA)&& (!(checkBot(ACK)))) {
				x=4;
			}

		setLED(GREEN_LED,OFF);
		setLED(RED_LED,OFF);
		setLED(YELLOW_LED,ON);
		delay(1000);


		setLED(YELLOW_LED,OFF);
		delay(1000);

		break;

		case 4:

		if((!(checkBot(OLA))) && (!(checkBot(FLA)))) {
			x=3;
		} else if (checkBot(OLA)) {
			x=5;
		}
		setLED(GREEN_LED,OFF);
		setLED(RED_LED,OFF);
		setLED(YELLOW_LED,ON);
		delay(100);

		break;
		case 5:

		if(!(checkBot(ACK))) {
			x=6;
		}
		setLED(GREEN_LED,OFF);
		setLED(YELLOW_LED,OFF);
		setLED(RED_LED,ON);
		delay(100);

		setLED(RED_LED,OFF);
		delay(100);

		break;

		case 6:

		setLED(GREEN_LED,OFF);
		setLED(YELLOW_LED,OFF);
		setLED(RED_LED,ON);
		delay(100);

		if(!(checkBot(OLA))) {
			x=4;
		}

		break;
	}
}
return 0;
}

