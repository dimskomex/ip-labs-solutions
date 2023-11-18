#include <stdio.h>
#define ERROR -1       /* Return value for illegal character */

int getinteger(int base)
{ char ch; /* No need to declare ch as int - no EOF handling */
  int val = 0;                    /* Initialize return value */
  while ((ch = getchar()) != '\n')    /* Read up to new line */
    if (ch >= '0' && ch <= '0'+base-1)   /* Legal character? */
      val = base*val + (ch-'0');      /* Update return value */
    else
      return ERROR;                /* Illegal character read */
  return val; /* Everything OK - Return value of number read */
}