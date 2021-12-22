#ifndef __ADXL345_H__
#define __ADXL345_H__

#include "alt_types.h"

#define ADXL345_ADDR 			   0x1D 
#define ADXL345_DATAX0_REG         0x32
#define ADXL345_DATAX1_REG         0x33
#define ADXL345_DATAY0_REG         0x34
#define ADXL345_DATAY1_REG         0x35
#define ADXL345_DATAZ0_REG         0x36
#define ADXL345_DATAZ1_REG         0x37
#define ADXL345_FIFO_CTL_REG       0x38
#define ADXL345_DATA_FORMAT_REG    0x31
#define ADXL345_POWER_CTL_REG	   0x2D

void ADXL345_write(alt_u32 reg_add, alt_u8 data);
alt_u8 ADXL345_read(alt_u32 reg_add);

#endif