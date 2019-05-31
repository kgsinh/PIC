void cmd(unsigned char y)
{
PORTB=y;
PORTC&=~(1<<0);
PORTC&=~(1<<1);
PORTC|=(1<<1);
delay_ms(10);
PORTC&=~(1<<1);
}

void dat(unsigned char y)
{
PORTB=y;
PORTC&=~(1<<0);
PORTC&=~(1<<1);
PORTC|=(1<<0);
PORTC|=(1<<1);
delay_ms(10);
PORTC&=~(1<<1);
}

void display(unsigned char z[])
{
unsigned char i;
for(i=0;z[i]!='\0';i++)
{
dat(z[i]);
}
}

void main()
{

float a;
unsigned char z[20],i,x[]={0x04,0x08,0x10,0x20},j=0;

TRISB=0x00;
TRISC=0x00;
PORTB=0x00;
PORTC=0x00;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

for(i=0;i<=50;i++)
{
PORTC&=0x00;
PORTC|=x[j];
j++;
delay_ms(1000);

a=i*1.8;
FloatToStr(a,z);
cmd(0x80);
display("Angle=");
cmd(0x86);
display(z);

if(j==4)
{
j=0;
}
}
}