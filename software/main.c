#include "system.h"
#include "opencores_i2c.h"
#include <stdint.h>
#include <stdio.h>
#include "sys/alt_stdio.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"

#include "adxl345.h"

int main()
{
	alt_16 x = 0, y = 0, z = 0;
	float ax = 0, ay = 0, az = 0;  
	alt_u8 data[6] = {0};
	alt_printf("Start the program\n");
	I2C_init(OPENCORES_I2C_0_BASE, NIOS2_CPU_FREQ, 100000);					// Initialization of I2C protocole
	ADXL345_write(ADXL345_POWER_CTL_REG, 0x08);								// Setting the accelerometer in measuring mode
	ADXL345_write(ADXL345_FIFO_CTL_REG, 0x9F);								// Configuration of FIFO control register 
	ADXL345_write(ADXL345_DATA_FORMAT_REG, 0x00);							// Configuration of DATA_FORMAT register : 10 bit mode AND g range = +- 2 g
	
	while(1)
	{
		for (int i = 0 ; i < 6 ; i++)
		{
			data[i] = ADXL345_read(ADXL345_DATAX0_REG + i); 
		}
		
		x = (alt_16)(data[1] << 8 | data[0]);
		y = (alt_16)(data[3] << 8 | data[2]);
		z = (alt_16)(data[5] << 8 | data[4]);
		
		ax = x  / 256;
		ay = y  / 256;
		az = z  / 256;
		// printing the values in terminal
		printf("\tX = %f\n", ax);
		printf("\tY = %f\n", ay);
		printf("\tZ = %f\n", az);
		
		usleep(100000);
	}
	
	
	return 0;
}