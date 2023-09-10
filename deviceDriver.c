/**************************************************************
* Title: Device Driver using FreeRTOS
* Author: Shubham Kumar Savita
* Description: The following code is written to demonstarte
*              Device Driver Development using FreeRTOS based
*              on Queues. The current repo has/will(have)
*              Device Driver developed based on this reference
*              and steps mentioned in README.md file.
* References: FreeRTOS.org, medium.com
***************************************************************/


#include <stdio.h>
#include <freeRTOS.h>
#include <task.h>
#include <queue.h>


// Data Structure Implementation

typedef struct{

    uint16_t deviceID;
    bool isDeviceBusy;
    QueueHandle_t deviceQ;
  
} d_driver;


// Device Initialization

void deviceInit(d_driver *device, uint16_t deviceID){

	device->deviceID = deviceID;
	device->isDeviceBusy = false;
	device->deviceQ = xQueueCreate(20, sizeof(int)); 
	if(device->deviceQ == NULL){
		printf("Error!! Queue NOT created.");
		/*need to handle it better.*/
	}

}

// Device function as FreeRTOS task

void deviceFunction(void *pvParameters){

	d_driver *dparam = (d_driver *)pvParameters;
	int request;
	while(1){
		if(xQueueReceive(dparam->deviceQ, &request, portMX_DELAY)){
			dparam->isDeviceBusy = true;
			/*need to write function of device here*/
			dparam->isDeviceBusy = false;		
		}	
	}
}

// Device interface function for other tasks to communicate with device.

void deviceInterface(d_driver *dInterface, int request){

	if(dInterface->isDeviceBusy){
		printf("Device busy, wait for release...!");
		/*need to add handle it better.*/
		return;
	}
	xQueueSend(dInterface->deviceQ, &request, portMX_DELAY);
}

// Create and Schedule FreeRTOS tasks for device function

void main(void){

	d_driver device;
	deviceInit(&device, 1);
	
	if(xTaskCreate(deviceFunction, "Device Function Task", configMINIMAL_STACK_SIZE, &device, 1, NULL) != pdPASS){
		printf("Error!! Task NOT created.");
		/*need to handle it better.*/		
	}
	vTaskStartScheduler(); //to start executing created task (device function task);
}



