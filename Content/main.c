#include "Cpu.h"  /* interface to CPU, do not remove */
#include "WAIT1.h"  /* waiting routines  */
#include "LEDG.h"   /* blueLED */
#include "LEDR.h"
#include "LEDB.h"

int main(void) {
  PE_low_level_init(); /* low level driver initialization, do not remove */

  for(;;) {
     /* add your code here */
      int a = 0;
      for (a=0; a<=10; a++) {
          LEDB_On();
          WAIT1_Waitms(50);
          LEDB_Off();
          WAIT1_Waitms(50);
      }
     LEDG_On();
     WAIT1_Waitms(100);
     LEDG_Off();
     LEDR_On();
     WAIT1_Waitms(1000);
     LEDR_Off();
     LEDB_On();
     WAIT1_Waitms(500);
     LEDB_Off();
  }
  /* do not leave main! */
  return 0;
}
