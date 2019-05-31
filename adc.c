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

void display(unsigned char z[])
{
unsigned char i;
cmd(0x80);
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

void main()
{
int x;
char z[20];

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

ADCON0=0x81;
ADCON1=0x80;

while(1)
{
ADCON0|=(1<<GO);
while((PIR1&(1<<ADIF))==0);
x=(ADRESH<<8|ADRESL);
sprinti(z,"%d",x);
display(z);
}
}