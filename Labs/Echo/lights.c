#include "Cpu.h"  /* interface to CPU, do not remove */
#include "WAIT1.h"  /* waiting routines  */
#include "LEDR.h"
#include "LEDG.h"
#include "LEDB.h"
#include <stdio.h> /* interface to standard I/O */

void blink(int n)
{
	int i;

	i = 0;

	LEDR_On();
	for (i = 0; i < (2*n); i++) {
		LEDR_Neg();
		WAIT1_Waitms(100);
	}
	LEDR_Off();
}
