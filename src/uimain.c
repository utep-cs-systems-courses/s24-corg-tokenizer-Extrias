#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  char userInp[100];
  List* history = init_history();

 
  while(1){
    printf("\nEnter a string (type 'q' to exit):");
    putchar('$');
    fgets(userInp, 100, stdin);

    printf("Your string: %s",userInp);

    //removing new line character
    size_t len = strlen(userInp);
    userInp[len - 1] = '\0';

    if(strcmp(userInp, "q") == 0){
      break;
    }

    char **tokens = tokenize(userInp);

    add_history(history, userInp);

    printf("\nHistory:\n");
    print_history(history);

    free_tokens(tokens);

    printf("\nEnter a number if you want to see a history number, to proceed just type 'p':\n");
    while(1){
      char userInp2[100];
      putchar('$');
      fgets(userInp2, 100, stdin);

      printf("You typed: %s", userInp2);
      
      if(strcmp(userInp2, "p\n") == 0){
	break;
      }
      get_history(history, atoi(userInp2));
      if(get_history(history, atoi(userInp2)) == NULL){
	printf("\nHistory number does not exist\n");
      }
      else{
	printf(get_history(history, atoi(userInp2)));
      }
      printf("\nEnter another number or 'p' to proceed\n");
    }
    
  }

  free_history(history);

 
  return 0;
}
