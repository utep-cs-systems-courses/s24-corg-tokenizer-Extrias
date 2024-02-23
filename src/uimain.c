#include "stdio.h"

int main(){

  char userInp[40];

  putchar('$');
  fgets(userInp, 40, stdin);

  printf(userInp);

  return 0;
}
