#define lcd PORTB
sbit rs at RC0_bit;
sbit en at RC1_bit;

void cmd(unsigned char y)
{
lcd=y;
rs=0;
en=1;
delay_ms(10);
en=0;
}

void dat(unsigned char y)
{
lcd=y;
rs=1;
en=1;
delay_ms(10);
en=0;
}

void main()
{
unsigned char i=123,a,b,c,d;

TRISB=0x00;
TRISC.RC0=0;
TRISC.RC1=0;
PORTB=0x00;
PORTC.RC0=0;
PORTC.RC1=0;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);

a=i%10;
d=i/10;
b=d%10;
c=d/10;
cmd(0x80);
dat(c+48);
cmd(0x81);
dat(b+48);
cmd(0x82);
dat(a+48);
}

