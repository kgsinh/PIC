#define lcd PORTB
sbit rs at RD0_bit;
sbit en at RD1_bit;

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
int y;
char z[20];

TRISB=0x00;
TRISD.RD0=0;
TRISD.RD1=0;
TRISC.RC1=1;
PORTB=0x00;
PORTD.RD0=0;
PORTD.RD1=0;

cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
cmd(0x80);

T1CON=0x03;
TMR1H=0;
TMR1L=0;

while(1)
{
do
{
y=(TMR1H<<8|TMR1L);
sprinti(z,"Count=%6d",y);
display(z);
}while(PIR1.TMR1IF==0);
PIR1.TMR1IF==0;
}
}