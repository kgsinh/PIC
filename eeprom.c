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

void i2c_stop()
{
SSPCON2.PEN=1;
while(PIR1.SSPIF==0);
PIR1.SSPIF=0;
}

void main()
{
i2c_init();

i2c_start();
i2c_wr(0xA0);
i2c_wr(0x1D);
i2c_wr(0x55);
i2c_stop();
}