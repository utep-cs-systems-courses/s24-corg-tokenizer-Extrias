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

}
