void main() 
{
int i;

TRISB=0x00;
PORTB=0x00;

while(1)
{
for(i=1;i<=128;i*=2)
{
PORTB=0x01*i;
delay_ms(500);
}
}
}