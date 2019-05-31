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
cmd(0x80);
dat('K');
}
