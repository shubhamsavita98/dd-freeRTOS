# DD_FreeRTOS
Device Driver using FreeRTOS based on queue for intertask communication.
Queue works as FIFO.

#Steps: 

1. Data Structure implementation
	- Device ID, Device Status, Device Queue

2. Initialize the device
	- Set initial conditions and queue	

3. Write device function
	- A task in FreeRTOS waits for request from queue

4. Implement an interface
	- To send request to the device to interact with device
	
	(TO CHECK: Implement data communication)

5. freeRTOS tasks creation
	- Create device function FreeRTOS Task
	- Scheduler (VTaskStartScheduler())


#References: medium.com
