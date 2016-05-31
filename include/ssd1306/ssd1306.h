#ifndef _SSD1306_H
#define _SSD1306_H

typedef struct _SSD1306 SSD1306;

typedef enum _SSD1306_ROWS {
	SSD1306_ROWS_NONE = 0,
	SSD1306_ROWS_32 = 32,
	SSD1306_ROWS_64 = 64
} SSD1306_ROWS;

typedef enum _SSD1306_VCCSTATE {
	SSD1306_VCCSATE_NONE = 0,
	SSD1306_VCCSATE_EXTERNAL = 1,
	SSD1306_VCCSATE_SWITCHCAP = 2
} SSD1306_VCCSTATE;

SSD1306* ssd1306_create(int spiChannel, int resetPin, int dcPin, int maxClockSpeed);

/*
 * destroy object and close SPI connection
 */
void ssd1306_destroy(SSD1306 * p);


/*
 * setup connection for display
 */
void ssd1306_init(SSD1306 * p, SSD1306_ROWS rowtype, SSD1306_VCCSTATE vccstate);


/*
 * reset display
 */
void ssd1306_reset(SSD1306 * p);


/*
 * start scrolling to the left
 */
void ssd1306_startScrollLeft(SSD1306 * p, int start, int stop);


/*
 * start scrolling to the right
 */
void ssd1306_startScrollRight(SSD1306 * p, int start, int stop);

/*
 * stop scrolling
 */

void ssd1306_stopScroll(SSD1306 * p);

/*
 * set (a part of) the memory of the display
 * by using the internal memory
 */
void ssd1306_displayBlock(SSD1306 * p, int row, int col, int col_count, int col_offset /* = 0 */);

/*
 * aquire the pointer to the memory that is
 * used for drawing and when displaying
 * this memory block is (width * height / 8) Bytes
 * the data is stored in column major order
 */
unsigned char * ssd1306_getDisplayMemory(SSD1306 * p);

/*
 * send command to display
 * attributes of setup commands are also commands
 * only the actual display data is sent as data
 */
void ssd1306_command(SSD1306 * p, unsigned char c);

/*
 * send data to display
 */
void ssd1306_data(SSD1306 * p, unsigned char * c, int len);

/*
 * Convenience functions
 * Drawing should actually be handled by another library
 */

/*
 * set whole display memory to either black or white
 */
void ssd1306_clear(SSD1306 * p, int color);

/*
 * set one pixel of the display
 * this is just a test function
 * the actual drawing should be handled
 * by a different library
 * col = 0 = black, col != 0 = white
 */
void ssd1306_setPixel(SSD1306 * p, int x, int y, int col);


/*
 * draw a line
 * col = 0 = black, col != 0 = white
 */
void ssd1306_drawLine(SSD1306 * p, int x0, int y0, int x1, int y1, int color);

/*
 * update the display to reflect the libraries internal buffer
 */
void ssd1306_display(SSD1306 * p);


/*
 * forward the delay function of wiringPi
 * Convenience
 */
void ssd1306_delay(unsigned int ms);

#endif

