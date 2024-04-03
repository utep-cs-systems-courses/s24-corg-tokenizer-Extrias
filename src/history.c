#include <stdio.h>
#include "history.h"
#include <stdlib.h>
#include <string.h>

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = (List *)malloc(sizeof(List));

  if(list == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  list -> root = NULL;
  return list;

}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  //Create new item
  Item *newItem = (Item *)malloc(sizeof(Item));
  if(newItem == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newItem->str = strdup(str); //duplicate string given
  if(newItem->str == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  //assigning id based on the place the item is gonna be
  int id = 0;
  if(list->root != NULL){
    Item *current = list->root;
    while(current->next != NULL){
      current = current->next;
      id++;
    }
    id++; //incrementing once more for the new item
  }

  
  newItem->id = id;
  newItem->next = NULL;

  //insert new item to the end of the list
  if(list->root == NULL){
    list->root = newItem;
  }
  else{
    Item *current = list->root;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newItem;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *current = list->root;
  while(current != NULL){
    if(current->id == id){
      return current->str;
    }
    current = current->next;
  }
  return NULL;  //return NULL if id not found
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if(list->root == NULL){
    printf("History is empty\n");
      return;
  }

  Item *current = list->root;
  while(current != NULL){
    printf("%d: %s\n", current->id, current->str);
    current = current->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    Item *temp = current;
    current = current->next;
    free(temp->str);
    free(temp);
  }
  free(list);
}


