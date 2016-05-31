#include <stdio.h>

#include "ssd1306/ssd1306.h"

int main(int argc, char * argv[])
{
	printf("Starting SSD1306 Test\n");

	int spiChannel = 0;
	int resetPin = 25;
	int dcPin = 24;
	printf("Using SPI Channel %d\n", spiChannel);
	printf("Reset Pin = %d, DC Pin = %d\n", resetPin, dcPin);

	/*
	 * MAX = 10 MHz
	 */

	int clock = 1000000;
	SSD1306 * disp = ssd1306_create(spiChannel, resetPin, dcPin, clock);

	printf("Init\n");
	ssd1306_init(disp, SSD1306_ROWS_64, SSD1306_VCCSATE_SWITCHCAP);

	int y = 0;
	int x = 0;
	for (; x < 100; x += 1) {
		for (y = 0; y < 10; ++y) {
			ssd1306_setPixel(disp, x, y, 1);
		}
	}


	for (x = 0; x < 100; x += 10) {
		for (y = 0; y < 10; ++y) {
			ssd1306_setPixel(disp, x, y, 0);
		}
	}

	printf("Display 10 white Boxes\n");
	ssd1306_display(disp);
	ssd1306_delay(1000);

	printf("Clear\n");
	ssd1306_clear(disp, 0);

	printf("Draw Lines\n");
	int i;
	for (i=0; i < 128; i+=4) {
		ssd1306_drawLine(disp, 0, 0, i, 64-1, 1);
		ssd1306_display(disp);
	}

	for (i=0; i < 64; i+=4) {
		ssd1306_drawLine(disp, 0, 0, 128-1, i, 1);
		ssd1306_display(disp);
	}

	printf("Start Scrool Right\n");
	ssd1306_startScrollRight(disp, 0x00, 0x0F);
	ssd1306_delay(2000);
	ssd1306_stopScroll(disp);
	ssd1306_delay(1000);

	printf("Start Scrool Left\n");
	ssd1306_startScrollLeft(disp, 0x00, 0x0F);
	ssd1306_delay(2000);
	ssd1306_stopScroll(disp);
	ssd1306_delay(1000);

	ssd1306_destroy(disp);

	return 0;
}
