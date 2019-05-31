void i2c_init()
{
SSPSTAT=0x80;
SSPCON=0x28;
SSPADD=39;
}

void i2c_start()
{
SSPCON2.SEN=1;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
}

void i2c_wr(unsigned char dat)
{
SSPBUF=dat;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
}

int i2c_rd()
{
SSPCON.RCEN=1;
SSPSTAT=1<<2;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
return SSPBUF;
}

void i2c_stop()
{
SSPCON2.PEN=1;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
}

void main()
{
TRISC.RC3=1;
TRISC.RC5=1;

TRISD=0x00;
PORTD=0x00;

i2c_init();

i2c_start();
i2c_wr(0xA0);
i2c_wr(0x1D);
i2c_wr(0x55);
i2c_stop();

delay_ms(1000);

i2c_start();
i2c_wr(0xA0);
i2c_wr(0x1D);

SSPCON2.RSEN=1;
while(PIR1.SSPIF==0);
PIR1.SSPIF==0;
i2c_wr(0xA1);
PORTD=i2c_rd();
i2c_stop();
}