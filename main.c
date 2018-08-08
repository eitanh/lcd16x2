#include <stdbool.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "main.h"
#include <util/delay.h>
#include "i2clcd.h"
#include "i2cmaster.h"

const char string_flash[] PROGMEM = "Hello Flash!";

int main(void)
{
	char string1[] = "Hello World!";

	i2c_init();
	lcd_init();

	lcd_light(true);
	lcd_print(string1);
	lcd_nextline();
	lcd_print_P(PSTR("I2CLCD V0.11"));

	// always set all three parameters  (ON/OFF) when using this command
	lcd_command(LCD_DISPLAYON | LCD_CURSORON | LCD_BLINKINGON);
	_delay_ms(1000);

	lcd_command(LCD_CLEAR);
	_delay_ms(2);
	lcd_print_P(string_flash);
	lcd_printlc_P(2, 2, string_flash);

	//-	Endless loop
	
	while (1) {
		
	}
}
