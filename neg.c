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

int adc_r(int ch)
{
adcon0=0x81;
adcon1=0x80;
adcon0|=(ch<<3);
adcon0.go=1;
while(pir1.adif==0);
pir1.adif=0;
return (adresh<<8|adresl);
}

void main()
{
int x,y,v;
char z[20];
trisa.ra0=1;
trisa.ra1=1;
trisb=0x00;
trisc.rc0=0;
trisc.rc1=0;
portb=0x00;
portc.rc0=0;
portc.rc1=0;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

adcon0=0x81;
adcon1=0x80;

while(1)
{
x=adc_r(0)/2;
y=adc_r(1)/2;

v=x-y;

sprinti(z,"Temp=%3d%cC",v,0xdf);
display(z);
}
}