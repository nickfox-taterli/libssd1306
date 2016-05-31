#ifndef _RPI_IO_H
#define _RPI_IO_H


typedef struct _RPIIO_SPI RPIIO_SPI;

typedef enum _PINMODE {
	PINMODE_NONE = 0,
	PINMODE_OUTPUT = 1,
	PINMODE_INPUT = 2
} PINMODE;


/*
 * GPIO needs to be initialized before assigning
 * values
 */
int rpiIO_initGPIO();

/*
 * set GPIO pin to input or output
 */
void rpiIO_pinMode(int gpioPin, PINMODE mode);


/*
 * set or clear GPIO pin
 */
void rpiIO_digitalWrite(int gpioPin, int value);


/*
 * create a SPI object which hides
 * the internals of the SPI
 * connection
 * pointer must be release by rpiIO_spiDestroy
 */
RPIIO_SPI * rpiIO_spiCreate(const char * devName, int maxClock);

/*
 * free the memory allocated by rpiIO_spiCreate
 */
void rpiIO_spiDestroy(RPIIO_SPI *);

/*
 * transmit data over the SPI bus
 * receive and transmit buffer have to be
 * of the same length
 * they can also be the same buffer
 */

int rpiIO_spiDataRW(RPIIO_SPI * p, unsigned char * tx, unsigned char * rx, int len);

#endif
