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

int AN_R(unsigned char ch)
{
ADCON0=0x81;
ADCON1=0x80;
ADCON0|=(ch<<3);
ADCON0.GO=1;
while(PIR1.ADIF==0);
PIR1.ADIF=0;
return (ADRESH<<8|ADRESL);
}

void main()
{
int x,y,v;
char z[20];
TRISA.RA0=1;
TRISA.RA1=1;
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
x=AN_R(0)/2;
y=AN_R(1)/2;

v=x-y;

sprinti(z,"Temp=%3d%cC",v,0xdf);
display(z);
}
}