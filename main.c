#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "services.c"

int main() {
  int year;

  printf("Informe um ano:\n> ");
  scanf("%i", &year);
  
  getYearHolidays(year);
  return 0;
}


