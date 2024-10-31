#include <stdio.h>

#define TRUE 1
#define FALSE 0

int mapper_days_of_month[] = {
    0,  // noop
    31, // Jan
    28, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31, // Dec
};

char *months[] = {" ",         "\n\n\nJan", "\n\n\nFeb", "\n\n\nMar",
                  "\n\n\nApr", "\n\n\nMay", "\n\n\nJun", "\n\n\nJul",
                  "\n\n\nAug", "\n\n\nSep", "\n\n\nOct", "\n\n\nNov",
                  "\n\n\nDec"};

int get_input_year(void) {
  int year;
  // scanf("%d", &year);
  // return year;
  while (scanf("%d", &year) != 1) {
    printf("You must input a correct format for year!\n");
    if (year < 0)
      printf("Year must large than 0.\n");
    continue;
  }
  printf("year= %d", year);
  return year;
}

int main() {
  int y = get_input_year();
  return 0;
}
// TODO
