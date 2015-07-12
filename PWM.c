
#include <htc.h>


void delay(int arb)
{
    while (arb > 0)
    {
        arb--;
    }
}



void dutycycleC2(unsigned int on)
{
	int i = 0;
	for (i=0;i<on;i++) {
            RC2=1;
        }
        delay(10);
	for (i=0;i<100-on;i++) {
            RC2=0;
        }
        delay(10);
}
void dutycycleC3(unsigned int on)
{
	int i = 0;
	for (i=0;i<on;i++) {
            RC3=1;
        }
        delay(10);
	for (i=0;i<100-on;i++) {
            RC3=0;
        }
        delay(10);
}
void dutycycleC4(unsigned int on)
{
	int i = 0;
	for (i=0;i<on;i++) {
            RC4=1;
        }
        delay(10);
	for (i=0;i<100-on;i++) {
            RC4=0;
        }
        delay(10);
}


void main()
{
    //INTCON &= ~(1<<GIE); // disable global & peripheral
    
    ADCON1 = 0x06;   // all digital outputs

    TRISC=0;  // Set PORTC as an Output
    PORTC=0;

    

    int r = 0;
    int g = 33;
    int b = 66;
    int dirR = 1;
    int dirG = 1;
    int dirB = 1;


    while(1)
   
    {

        dutycycleC2(r);
        dutycycleC3(g);
        dutycycleC4(b);

        r = r + dirR;

        if (r == 100)
            dirR = -1;
        if (r == 0)
            dirR = 1;

        g = g + dirG;

        if (g == 100)
            dirG = -1;
        if (g == 0)
            dirG = 1;

        b = b + dirB;

        if (b == 100)
            dirB = -1;
        if (b == 0)
            dirB = 1;

    }
}


