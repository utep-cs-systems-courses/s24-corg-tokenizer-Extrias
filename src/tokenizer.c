#include <stdio.h>
#include <tokenizer.h>

int space_char(char c){
  if((c == '\t' || c == ' ') && c != '\0'){
    return 1;
  }
  else {
    return 0;
  }
}
