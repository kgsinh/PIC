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
unsigned char y;
TRISC.RC6=0;
TRISC.RC7=1;
SPBRG=103;
TXSTA.BRGH=1;
RCSTA.SPEN=1;
TXSTA.TXEN=1;
RCSTA.CREN=1;

while(1)
{
while(PIR1.RCIF==0);
y=RCREG;

if(y=='A')
{
trans("B");
}

if(y=='C')
{
trans("D");
}

if(y=='E')
{
trans("F");
 }
}
}