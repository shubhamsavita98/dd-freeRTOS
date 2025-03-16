/**************************************************************************
* Title: basic skeleton of SPI device driver (abstraction layer/interfaces)
* Author: Shubham Kumar Savita
* Description: The following code is written to demonstarte
*              basic SPI Device Driver Development. The idea is
               to create an abstraction layer so that different
			   (for different hardware and configurations)
			   SPI drivers can be used interchangebly without 
			   changing the application logic.
			   * References: FreeRTOS.org, medium.com
***************************************************************************/


// list of spi functions
typedef struct{
	void (*init)(); 
	void (*read)(uint8_t* buffer, uint32_t size);
	void (*write)(uint8_t* buffer, uint32_t size);
}DeviceDriver;

// function implementations/definitions

void spiInit(){
	/*initialization function implementation*/
	/*...*/
	}
	
void spiRead(uint8_t* buffer, uint32_t size){
	/*read function implementation*/
	/*...*/
	}

void spiWrite(uint8_t* buffer, uint32_t size){
	/*write function implementation*/
	/*...*/
	}


// create an SPI driver object
DeviceDriver spi_driver = {spiInit, spiRead, spiWrite};

int main(){
	
	spi_driver.init(); // this calls spiInit because void (*init)() = spiInit;
	
	// buffer for read and write operations
	uint8_t buffer_spi[10];
	
	spi_driver.read(buffer_spi, sizeof(buffer_spi));
	spi_driver.write(buffer_spi, sizeof(buffer_spi));
	
	
	return 0;
}
