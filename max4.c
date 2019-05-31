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
TRISC=0x00;
PORTC=0x00;
SSPSTAT=0x00;
SSPCON=0x21;

maxx(0x09,0x0F);
maxx(0x0A,0x0F);
maxx(0x0B,0x03);
maxx(0x0C,0x01);
maxx(0x01,4);
maxx(0x02,3);
maxx(0x03,2);
maxx(0x04,1);
}
