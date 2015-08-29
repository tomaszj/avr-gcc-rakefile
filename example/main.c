#include <avr/io.h>

#include "test_routines.h"

int main(void)
{
  while(1)
  {
    asm("nop");
    test_routine();
  }
}
