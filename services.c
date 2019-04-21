char weekDays[7][13] = {
  "Domingo",
  "Segunda-Feira", 
  "Terça-Feira",
  "Quarta-Feira",  
  "Quinta-Feira",
  "Sexta-Feira",
  "Sabado"
};

int monthDays[2][13] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int sumDays[2][13] = {
  {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
  {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
};

int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getYearDay(int day, int mon, int year) {
  int leap = isLeapYear(year);
  return sumDays[leap][mon] + day;
}

int getMonth(int d, int y) {
  int i, count = 0;
  int leap = isLeapYear(y);

  for(i = 0; i<12; i++) {
    count += monthDays[leap][i];
    if(d <= count) return i+1;
  }
}

int getMonthDay(int d, int y) {
  int i, count = 0;
  int leap = isLeapYear(y);

  for(i = 0; i<12; i++) {
    count += monthDays[leap][i];
    if(d <= count) return (d - sumDays[leap][i+1]);
  }
}

int getWeekDay(int d, int m, int y) {
  return (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
}

void printHoliday(int day, int month, int year, char holiday[]) {
  printf("> %i/%i/%i (%s): %s\n", day, month, year, weekDays[getWeekDay(day, month, year)], holiday);
}

void getGreyWednesday(int day, int month, int year) {
  int yearDay = getYearDay(day, month, year) - 46;
  printHoliday(getMonthDay(yearDay, year), getMonth(yearDay, year), year, "Quarta Feira de Cinzas");
}

int getEasterDay(int year) {
  int easterDate, easterMonth, christDay, christMonth;
  int a, b, c, d, e, f, g, h, i, j, k, l, m, n;
  a=b=c=d=e=f=g=h=i=j=k=l=m=n=0;

  a = year%19;
  b = year/100;
  c = year%100;
  d = b/4;
  e = b%4;
  f = (b+8)/25;
  g = (b-f+1)/3;
  h = ((19*a)+b-d-g+15)%30;
  i = c/4;
  j = c%4;
  k = (32+(2*e)+(2*i)-h-j)%7;
  l = (a+(11*h)+(22*k))/451;
  easterMonth = (h+k-(7*l)+114)/31;
  n = (h+k-(7*l)+114)%31;
  easterDate = n+1;
  
  if(easterDate == 2) {
    christDay = 31;
    christMonth = 3;
  } else if (easterDate == 1) {
    christDay = 30;
    christMonth = 3;
  } else {
    christDay = easterDate-2;
    christMonth = easterMonth;
  }

  getGreyWednesday(easterDate, easterMonth, year);
  printHoliday(christDay, christMonth, year, "Paixão de Cristo");
  printHoliday(easterDate, easterMonth, year, "Pascoa");

  return easterDate;
}

void getYearHolidays(int year) {
  if (year < 0001 || year > 5000) {
    printf("Infelizmente os calculos de datas não são válidas para o ano informado.");
    return;
  };

  int leap = isLeapYear(year);

  printf("\nAno de %d.\n", year);
  if(leap == 1) printf("Ano bissexto, possui ao todo 366 dias.\n");
  else printf("Ano não bissexto, possui ao todo 365 dias.\n");

  printf("\n-- Feriados --\n");
  
  printHoliday(1, 1, year, "Ano Novo");
  int easterDay = getEasterDay(year);
  printHoliday(20, 8, year, "Aniversário da cidade São Bernardo do Campo");
  printHoliday(25, 12, year, "Natal");

}