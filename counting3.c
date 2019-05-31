#define ssd PORTC
#define num PORTD

void display(unsigned char k)
{
unsigned char z[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
ssd=z[k];
}

void main()
{
unsigned char i,a,b,c,d,h;

TRISC=0x00;
TRISD.RD0=0;
TRISD.RD1=0;
TRISD.RD2=0;
PORTC=0x00;
PORTC.RD0=0;
PORTC.RD1=0;
PORTC.RD2=0;

while(1)
{
for(i=0;i<=999;i++)
{
a=i%10;
d=i/10;
b=d%10;
c=d/10;

for(h=1;h<=5;h++)
{
num=0x06;
display(a);
delay_ms(25);

num=0x05;
display(b);
delay_ms(25);

num=0x03;
display(c);
delay_ms(25);
}
}
}
}
