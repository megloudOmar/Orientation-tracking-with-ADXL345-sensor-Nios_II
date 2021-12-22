LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY accelerometer IS
	PORT (
		CLOCK_50 : IN STD_LOGIC;
		KEY : IN STD_LOGIC;
		I2C_SCL : INOUT STD_LOGIC;
		I2C_SDA : INOUT STD_LOGIC
	);
END accelerometer;


ARCHITECTURE accelerometer_rtl OF accelerometer IS

COMPONENT nios_system
        port (
            clk_clk                  : in    std_logic                    := 'X'; -- clk
            reset_reset_n            : in    std_logic                    := 'X'; -- reset_n
            opencores_i2c_scl_pad_io : inout std_logic                    := 'X'; -- scl_pad_io
            opencores_i2c_sda_pad_io : inout std_logic                    := 'X'  -- sda_pad_io
        );
end component nios_system;
 
	 
begin
    u0 : nios_system
        port map (
            clk_clk                  => CLOCK_50,                 --       clk.clk
            reset_reset_n            => KEY,    				      --       reset.reset_n
            opencores_i2c_scl_pad_io => I2C_SCL, 						-- 		opencores_i2c.scl_pad_io
            opencores_i2c_sda_pad_io => I2C_SDA  						--       opencores_i2c.sda_pad_io
        );

END accelerometer_rtl;