#define ssd PORTC
#define num PORTD

void display(unsigned char k)
{
unsigned char z[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
ssd=z[k];
}

void main() 
{
unsigned char i=13,a,b;

TRISC=0x00;
TRISD.RD0=0;
TRISD.RD1=0;
PORTC=0x00;
PORTD.RD0=0;
PORTD.RD1=0;

 while(1)
 {
a=i%10;
b=i/10;

num=0x02;
display(a);
delay_ms(50);

num=0x01;
display(b);
delay_ms(50);
  }
}