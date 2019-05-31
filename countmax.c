void maxx(char add,char dat)
{
PORTC.RC0=0;
SSPBUF=add;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
SSPBUF=dat;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
PORTC.RC0=1;
}

void main()
{
int i,j,k;

TRISC=0x00;
PORTC=0x00;
SSPSTAT=0x00;
SSPCON=0x21;

maxx(0x09,0x0F);
maxx(0x0A,0x0F);
maxx(0X0B,0x03);
maxx(0x0C,0x01);

while(1)
{
for(k=0;k<=9;k++)
{
maxx(0x03,k);
for(j=0;j<=9;j++)
{
maxx(0x02,j);
for(i=0;i<=9;i++)
{
maxx(0x01,i);
delay_ms(200);
}
}
}
}
}