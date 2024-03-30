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

int non_space_char(char c){
  if((c != '\t' || c != ' ') && c != '\0'){
    return 1;
  }
  else {
    return 0;
  }
}


char *token_start(char *s) {
    while (*s && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')) {
        s++;
    }

    if (*s == '\0') {
        return NULL;
    }

    return s;
}

char *token_terminator(char *token) {
    // Find the end of the token
    while (*token && !(*token == ' ' || *token == '\t' || *token == '\n' || *token == '\r')) {
        token++;
    }

    // Return pointer to the terminator character
    return token;
}

int count_tokens(char *s){
  int count = 0;
  int in_token = 0; //flag to track if inside token

  //iterate through string
  while(*s){
    //check for the start of the token
    if(*s != ' ' || *s == '\t' || *s == '\n' || *s == '\r'){
      if(!in_token){
	in_token = 1;
	count++;
      }
    }
    else{
      in_token = 0; //resets flag when it sees a token
    }

    *s++;
  }
  return count;
}

char *copy_str(char *inStr, short len){

  char *copy = (char *) malloc((len + 1) * (sizeof(char)));

  if(copy == NULL){
    fprintf(stderr, "Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }

  copy[len] = '\0';

  return copy;
}
