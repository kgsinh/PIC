void main() 
{
int i;
TRISB=0x00;
PORTB=0x00;
while(1)
{
for(i=0;i<=256;i++)
{
 PORTB=0x01*i;
 delay_ms(500);
 i*=2;
}
}
}