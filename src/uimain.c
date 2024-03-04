#include "stdio.h"

int main(){

  char userInp[40];

  putchar('$');
  fgets(userInp, 40, stdin);

  printf(userInp);
  printf("hola\nhola\nhola");

  return 0;
}
