void main() 
{
TRISB=0x00;
PORTB=0x00;
while(1)
{
PORTB=0x55;
delay_ms(500);
PORTB=0xaa;
delay_ms(500);
}

}