#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

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


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int token_count = 0;
  char **tokens = NULL;
  char *token_start = NULL;

  //count number of tokens
  for(char *p = str; *p; p++){
    if(*p != ' '){
      token_count++;
      while(*p && *p != ' '){ //skip the token until next space
	p++;
      }
    }
  }

  tokens = (char **) malloc((token_count + 1) * sizeof(char *));
  if(tokens == NULL){
    fprintf(stderr, "Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }

  //tokenizing string
  int i = 0;
  for(char *p = str; *p; p++){
    if(*p != ' '){
      token_start = p;
      while(*p && *p != ' '){
	p++;
      }

      int token_len = p - token_start;
      tokens[i] = (char *) malloc((token_len + 1) * sizeof(char));
      if(tokens[i] == NULL){
	fprintf(stderr, "Memory Allocation Failed\n");
	exit(EXIT_FAILURE);
      }

      for(int j = 0; j < token_len; j++){
	tokens[i][j] = token_start[j];

      }
      tokens[i][token_len] = '\0'; //Null terminate the token
      i++;
    }
  }
  tokens[token_count] = NULL;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != NULL; i++){
    printf("Token %d: %s\n", i+1, tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){

  for(int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }

  free(tokens);
}

