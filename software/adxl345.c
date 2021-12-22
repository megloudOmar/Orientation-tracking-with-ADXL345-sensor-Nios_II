#include "adxl345.h"

/* Function to write data in a register
inputs
      reg_add = the base address of the register
      data 	  = data to write
*/
void ADXL345_write(alt_u32 reg_add, alt_u8 data){
	I2C_start(OPENCORES_I2C_0_BASE, ADXL345_ADDR, 0);											
 	I2C_write(OPENCORES_I2C_0_BASE, reg_add, 0);							
	I2C_write(OPENCORES_I2C_0_BASE, data, 1);								
}

/* Function to read data from a register
inputs
      reg_add = the base address of the register
*/
alt_u8 ADXL345_read(alt_u32 reg_add){
	alt_u8 data;
	I2C_start(OPENCORES_I2C_0_BASE, ADXL345_ADDR, 0);						// accelerometer address in write mode	
	I2C_write(OPENCORES_I2C_0_BASE, reg_add, 0);							// write the address of the register that we want to read
	I2C_start(OPENCORES_I2C_0_BASE, ADXL345_ADDR, 1);						// accelerometer address in read mode
	data = I2C_read(OPENCORES_I2C_0_BASE, 1);								// storing data received from the slave
}