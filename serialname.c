void trans(unsigned char z[])
{
unsigned char i;

for(i=0;z[i]!='\0';i++)
{
while(PIR1.TXIF==0);
TXREG=z[i];
PIR1.TXIF=1;
}
}

void main() 
{
TRISC.RC6=0;
TRISC.RC7=1;
SPBRG=25;
TXSTA.TXEN=1;
RCSTA.SPEN=1;
trans("HELLO");

}