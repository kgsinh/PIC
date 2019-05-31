#define sm PORTB
void main() 
{
unsigned char i,z[]={0x81,0x42,0x24,0x18},j=0;

TRISB=0x00;
PORTB=0x00;

for(i=0;i<33;i++)
{
sm=z[j];
j++;
delay_ms(1000);
if(j==4)
{
j=0;
}
}
}