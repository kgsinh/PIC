sbit sw at rd5_bit;

void main() 
{
TRISD.RD5=1;
TRISB=0x00;
PORTB=0x00;
while(1)
{
if(sw==1)
{
PORTB=0x55;
delay_ms(500);
PORTB=0xaa;
delay_ms(500);
}
else
{
PORTB=0x00;
}
}
}