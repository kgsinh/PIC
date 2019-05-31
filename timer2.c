void delay()
{
T2CON=0x04;
TMR2=56;
while(PIR1.TMR2IF==0);
PIR1.TMR2IF=0;
}

void main() 
{
TRISB=0x00;
PORTB=0x00;

while(1)
{
PORTB=0x55;
delay();
PORTB=0xaa;
delay();
}
}