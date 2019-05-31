#define sm PORTB
void main()
{
unsigned char z[]={0x01,0x02,0x04,0x08},i;

TRISB=0x00;
PORTB=0x00;

while(1)
{
for(i=0;i<=3;i++)
{
sm=z[i];
delay_ms(1000);
}
}
}