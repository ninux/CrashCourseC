#include "Cpu.h"  /* interface to CPU, do not remove */
#include "WAIT1.h"  /* waiting routines  */
#include "LEDR.h"
#include "LEDG.h"
#include "LEDB.h"
#include <stdio.h> /* interface to standard I/O */

#define BLINKTIME 20

#define CMD_HELP_RED	"r = red"
#define CMD_HELP_GREEN	"g = green"
#define CMD_HELP_BLUE	"b = blue"
#define CMD_HELP_HELP	"h = help"
#define CMD_HELP_QUIT	"q = quit"

#define CMD_HELP	CMD_HELP_RED"\n\t" \
			CMD_HELP_GREEN"\n\t" \
			CMD_HELP_BLUE"\n\t" \
			CMD_HELP_HELP"\n\t" \
			CMD_HELP_QUIT

typedef enum {
	RED,
	GREEN,
	BLUE
} color_t;

void blink(int n, color_t c);
void blink_red(int n);
void blink_green(int n);
void blink_blue(int n);
void show_help(void);

void blink(const int n, const color_t c)
{
	switch (c) {
	case RED:	blink_red(n);	break;
	case GREEN:	blink_green(n);	break;
	case BLUE:	blink_blue(n);	break;
	default:	break;
	}
}

void blink_red(const int n)
{
	int i;
	i = 0;
	for (i = 0; i < (2*n); i++) {
		LEDR_Neg();
		WAIT1_Waitms(BLINKTIME);
	}
	LEDR_Off();
}

void blink_green(const int n)
{
	int i;
	i = 0;
	for (i = 0; i < (2*n); i++) {
		LEDG_Neg();
		WAIT1_Waitms(BLINKTIME);
	}
	LEDG_Off();
}

void blink_blue(const int n)
{
	int i;
	i = 0;
	for (i = 0; i < (2*n); i++) {
		LEDB_Neg();
		WAIT1_Waitms(BLINKTIME);
	}
	LEDB_Off();
}

void show_help(void)
{
	printf("\n\t"CMD_HELP"\n");
}

int main(void) {
	PE_low_level_init(); /* low level driver initialization, do not remove */

	blink(10, RED);	/* startup */
	char c = 0;
	printf("\n\t"CMD_HELP"\n");
	while (c != 'q') {
		printf("> ");
		fflush(stdout);
		scanf("%c", &c);
		printf("%c\n", c);
		switch (c) {
		case 'r': blink(3, RED); break;
		case 'g': blink(3, GREEN); break;
		case 'b': blink(3, BLUE); break;
		case 'h': printf("\n\t"CMD_HELP"\n");
		case 'q': break;
		default: break;
		}
		/* WAIT1_Waitms(1000); */
	}

	while (1) {
		blink(1, RED);
		blink(1, GREEN);
		blink(1, BLUE);
	}

	return 0;
}
