//Sensor I2C address
#define BMX_ACCL_ADDR     	0x19
#define BMX_GYRO_ADDR	  	0x68
//#define BMX_MAG_ADDR		0x12
#define BMX_MAG_ADDR		0x13
//#define BMX_MAG_ADDR		0x13


//Acclerometer Register
#define BMX_ACC_CHIPID		0x00

#define BMX_ACC_X_LSB		0x02
#define BMX_ACC_X_MSB		0x03
#define BMX_ACC_Y_LSB		0x04
#define BMX_ACC_Y_MSB		0x05
#define BMX_ACC_Z_LSB		0x06	
#define BMX_ACC_Z_MSB		0x07

#define BMX_ACC_TEMP		0x08

#define BMX_ACC_INT_STATUS_0	0x09
#define BMX_ACC_INT_STATUS_1	0x0A
#define BMX_ACC_INT_STATUS_2	0x0B
#define BMX_ACC_INT_STATUS_3	0x0C

#define BMX_ACC_FIFO_STATUS	0x0E

#define BMX_ACC_PMU_RANGE	0x0F
#define BMX_ACC_PUM_BW		0x10
#define BMX_ACC_PUM_LPW		0x11
#define BMX_ACC_PUM_LOW_POWER	0x12

#define	BMX_ACC_HBW		0x13

#define	BMX_ACC_BGW_SREST	0x14

#define	BMX_ACC_INT_EN_0	0x16
#define	BMX_ACC_INT_EN_1	0x17
#define	BMX_ACC_INT_EN_2	0x18

#define	BMX_ACC_INT_MAP_0	0x19
#define	BMX_ACC_INT_MAP_1	0x1A
#define	BMX_ACC_INT_MAP_2	0x1B

#define	BMX_ACC_INT_SRC		0x1D

#define	BMX_ACC_INT_OUT_CTL	0x20

#define	BMX_ACC_INT_RST_LATCH	0x21

#define	BMX_ACC_INT_0		0x22
#define	BMX_ACC_INT_1		0x23
#define	BMX_ACC_INT_2		0x24
#define	BMX_ACC_INT_3		0x25
#define	BMX_ACC_INT_4		0x26
#define	BMX_ACC_INT_5		0x27
#define	BMX_ACC_INT_6		0x28
#define	BMX_ACC_INT_7		0x29
#define	BMX_ACC_INT_8		0x2A
#define	BMX_ACC_INT_9		0x2B
#define	BMX_ACC_INT_A		0x2C
#define	BMX_ACC_INT_B		0x2D
#define	BMX_ACC_INT_C		0x2E
#define	BMX_ACC_INT_D		0x2F

#define	BMX_ACC_FIFO_CONFIG_0	0x30

#define	BMX_ACC_PMU_SELF_TEST	0x32

#define	BMX_ACC_TRIM_NVM_CTRL	0x33

#define	BMX_ACC_BGW_SPI3_WDT	0x34

#define	BMX_ACC_OFC_CTRL	0x36
#define	BMX_ACC_OFC_SETTING	0x37
#define	BMX_ACC_OFC_OFFSET_X	0x38
#define	BMX_ACC_OFC_OFFSET_Y	0x39
#define	BMX_ACC_OFC_OFFSET_Z	0x3A

#define	BMX_ACC_TRIM_GP_0	0x3B
#define	BMX_ACC_TRIM_GP_1	0x3C

#define	BMX_ACC_FIFO_CONFIG_1	0x3E

#define	BMX_ACC_FIFO_DATA	0x3F

//#define BMX_ACC_PMU_RANGE   		0x0f
#define BMX_ACC_PMU_RW			0x10
#define BMX_ACC_PMU_LPW			0x11
#define BMX_ACC_PMU_POWER		0x12
//#define BMX_ACC_HBW			0x13
#define BMX_ACC_BGW_SOFTRESET 		0x14
#define BMX_ACC_PMU_SELFTEST  		0x32
//#define BMX_ACC_FIFO_CONFIG_1 		0x3e


//Acclerometer Register value
#define BMX_ACC_SRSET			0xB6
#define BMX_ACC_PMU_NORMAL		0x00
#define BMX_ACC_PMU_SUSPEND		0x80
#define BMX_ACC_PMU_LPW_EN		0x40
#define BMX_ACC_PMU_DEEP_SUSPEND 	0x20

#define BMX_ACC_PMU_SLEEP_0_5_MS 	0x05
#define BMX_ACC_PMU_SLEEP_1_MS	 	0x06
#define BMX_ACC_PMU_SLEEP_2_MS 		0x07
#define BMX_ACC_PMU_SLEEP_4_MS 		0x08
#define BMX_ACC_PMU_SLEEP_6_MS 		0x09
#define BMX_ACC_PMU_SLEEP_10_MS 	0x0A
#define BMX_ACC_PMU_SLEEP_25_MS 	0x0B
#define BMX_ACC_PMU_SLEEP_50_MS 	0x0C
#define BMX_ACC_PMU_SLEEP_100_MS 	0x0D
#define BMX_ACC_PMU_SLEEP_500_MS 	0x0E
#define BMX_ACC_PMU_SLEEP_1K_MS 	0x0F

#define	BMX_ACC_PMU_LPM2		0x40
#define	BMX_ACC_PMU_EST			0x20

#define BMX_ACC_BW_7_81_HZ		0x08
#define BMX_ACC_BW_15_63HZ		0x09
#define BMX_ACC_BW_31_25HZ		0x0A
#define BMX_ACC_BW_62_5HZ		0x0B
#define BMX_ACC_BW_125HZ		0x0C
#define BMX_ACC_BW_250HZ		0x0D
#define BMX_ACC_BW_500HZ		0x0E
#define BMX_ACC_BW_1KHZ			0x0F

#define BMX_ACC_PMU_RANGE_2G	0x03
#define BMX_ACC_PMU_RANGE_4G	0x05
#define BMX_ACC_PMU_RANGE_8G	0x08
#define BMX_ACC_PMU_RANGE_16G	0x0C

#define BMX_ACC_FIFO_FULL_INT	0x20

#define BMX_ACC_FIFO_MODE_BYPASS	0
#define BMX_ACC_FIFO_MODE_FIFO		0x40
#define BMX_ACC_FIFO_MODE_STREAM	0x80

#define BMX_ACC_FIFO_SELECT_XYZ	0x00
#define BMX_ACC_FIFO_SELECT_X	0x01
#define BMX_ACC_FIFO_SELECT_Y	0x02
#define BMX_ACC_FIFO_SELECT_Z	0x03

#define	BMX_ACC_FIFO_OVERRUN_FLAG	0x80


//Gyroscope Register
#define BMX_GYRO_CHIPID		0x00

#define BMX_GYRO_X_LSB		0x02
#define BMX_GYRO_X_MSB		0x03
#define BMX_GYRO_Y_LSB		0x04
#define BMX_GYRO_Y_MSB		0x05
#define BMX_GYRO_Z_LSB		0x06	
#define BMX_GYRO_Z_MSB		0x07

#define BMX_GYRO_INT_STATUS_0	0x09
#define BMX_GYRO_INT_STATUS_1	0x0A
#define BMX_GYRO_INT_STATUS_2	0x0B
#define BMX_GYRO_INT_STATUS_3	0x0C

#define BMX_GYRO_FIFO_STATUS	0x0E

#define BMX_GYRO_RANGE		0x0F
#define BMX_GYRO_BW		0x10
#define BMX_GYRO_LPM1		0x11
#define BMX_GYRO_LPM2		0x12

#define	BMX_GYRO_RATE_HBW	0x13

#define	BMX_GYRO_BGW_SREST	0x14

#define	BMX_GYRO_INT_EN_0	0x15
#define	BMX_GYRO_INT_EN_1	0x16

#define	BMX_GYRO_INT_MAP_0	0x17
#define	BMX_GYRO_INT_MAP_1	0x18
#define	BMX_GYRO_INT_MAP_2	0x19

#define	BMX_GYRO_REG_1A		0x1A
#define	BMX_GYRO_REG_1B		0x1B
#define	BMX_GYRO_REG_1C		0x1C
#define	BMX_GYRO_REG_1E		0x1E

#define	BMX_GYRO_INT_RST_LATCH	0x21

#define	BMX_GYRO_HIGH_TH_X	0x22
#define	BMX_GYRO_HIGH_DUR_X	0x23
#define	BMX_GYRO_HIGH_TH_Y	0x24
#define	BMX_GYRO_HIGH_DUR_Y	0x25
#define	BMX_GYRO_HIGH_TH_Z	0x26
#define	BMX_GYRO_HIGH_DUR_Z	0x27

#define	BMX_GYRO_SOC		0x31	//Slow Offset Cancellation
#define	BMX_GYRO_A_OC		0x32	//Fast Offset Cancellation

#define	BMX_GYRO_TRIM_NVM_CTRL	0x33

#define	BMX_GYRO_BGW_SPI3_WDT	0x34

#define	BMX_GYRO_OFC_1		0x36
#define	BMX_GYRO_OFC_2		0x37
#define	BMX_GYRO_OFC_3		0x38
#define	BMX_GYRO_OFC_4		0x39

#define	BMX_GYRO_TRIM_GP_0	0x3A
#define	BMX_GYRO_TRIM_GP_1	0x3B

#define	BMX_GYRO_BIST		0x3C	//Built in Self-test

#define	BMX_GYRO_FIFO_CONFIG_0	0x3D
#define	BMX_GYRO_FIFO_CONFIG_1	0x3E

#define	BMX_GYRO_FIFO_DATA	0x3F


//Gyroscope Register value
#define BMX_GYRO_SRSET			0xB6

#define BMX_GYRO_PMU_SUSPEND		0x80
#define BMX_GYRO_PMU_DEEP_SUSPEND 	0x20

#define BMX_GYRO_PMU_SLEEP_0_5_MS 	0x05
#define BMX_GYRO_PMU_SLEEP_1_MS	 	0x06
#define BMX_GYRO_PMU_SLEEP_2_MS 		0x07
#define BMX_GYRO_PMU_SLEEP_4_MS 		0x08
#define BMX_GYRO_PMU_SLEEP_6_MS 		0x09
#define BMX_GYRO_PMU_SLEEP_10_MS 	0x0A
#define BMX_GYRO_PMU_SLEEP_25_MS 	0x0B
#define BMX_GYRO_PMU_SLEEP_50_MS 	0x0C
#define BMX_GYRO_PMU_SLEEP_100_MS 	0x0D
#define BMX_GYRO_PMU_SLEEP_500_MS 	0x0E
#define BMX_GYRO_PMU_SLEEP_1K_MS 	0x0F

#define	BMX_GYRO_PMU_LPM2		0x40
#define	BMX_GYRO_PMU_EST		0x20

#define BMX_GYRO_BW_7_81_HZ		0x08
#define BMX_GYRO_BW_15_63HZ		0x09
#define BMX_GYRO_BW_31_25HZ		0x0A
#define BMX_GYRO_BW_62_5HZ		0x0B
#define BMX_GYRO_BW_125HZ		0x0C
#define BMX_GYRO_BW_250HZ		0x0D
#define BMX_GYRO_BW_500HZ		0x0E
#define BMX_GYRO_BW_1KHZ		0x0F

#define BMX_GYRO_RANGE_2K_DPS		0x00		//2000 degree per secsond
#define BMX_GYRO_RANGE_1K_DPS		0x01		//1000 degree per secsond
#define BMX_GYRO_RANGE_500_DPS		0x02		//500  degree per secsond
#define BMX_GYRO_RANGE_250_DPS		0x03		//250  degree per secsond
#define BMX_GYRO_RANGE_125_DPS		0x04		//125  degree per secsond

#define BMX_GYRO_FIFO_FULL_INT	0x20

#define BMX_GYRO_FIFO_MODE_BYPASS	0
#define BMX_GYRO_FIFO_MODE_FIFO	0x40
#define BMX_GYRO_FIFO_MODE_STREAM	0x80

#define BMX_GYRO_FIFO_SELECT_XYZ	0x00
#define BMX_GYRO_FIFO_SELECT_X	0x01
#define BMX_GYRO_FIFO_SELECT_Y	0x02
#define BMX_GYRO_FIFO_SELECT_Z	0x03

#define	BMX_GYRO_FIFO_OVERRUN_FLAG	0x80

//Magnetometer Register
#define BMX_MAG_ID			0x40
#define BMX_MAG_X_LSB			0x42
#define BMX_MAG_X_MSB			0x43
#define BMX_MAG_Y_LSB			0x44
#define BMX_MAG_Y_MSB			0x45
#define BMX_MAG_Z_LSB			0x46
#define BMX_MAG_Z_MSB			0x47
#define BMX_MAG_RHALL_LSB		0x48
#define BMX_MAG_RHALL_MSB		0x49

#define BMX_MAG_INT_STATE		0x4A	
#define BMX_MAG_CTRL_0			0x4B
#define BMX_MAG_CTRL_1			0x4C
#define BMX_MAG_INT_CONFIG		0x4D
#define BMX_MAG_CONFIG			0x4E

#define BMX_MAG_THR			0x4F
#define BMX_MAG_HIGH_THR		0x50

#define BMX_MAG_REPXY			0x51
#define BMX_MAG_REPZ			0x52

//Magnetometer Register Value
#define BMX_MAG_SUSPEND			0x80

#define BMX_MAG_DATA_RATE_10HZ		0x00
#define BMX_MAG_DATA_RATE_2HZ		(0x01<<2)
#define BMX_MAG_DATA_RATE_6HZ		(0x02<<2)
#define BMX_MAG_DATA_RATE_8HZ		(0x03<<2)
#define BMX_MAG_DATA_RATE_15HZ		(0x04<<2)
#define BMX_MAG_DATA_RATE_20HZ		(0x05<<2)
#define BMX_MAG_DATA_RATE_25HZ		(0x06<<2)
#define BMX_MAG_DATA_RATE_30HZ		(0x07<<2)




