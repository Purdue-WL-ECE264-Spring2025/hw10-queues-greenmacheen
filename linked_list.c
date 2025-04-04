#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
  struct list_node newNode = { value, NULL}; 
  return newNode;
}

void insert_at_head(struct linked_list *list, size_t value) {
   newNode = list_node(value);
   newNode.next = list.head;
  
}

void insert_at_tail(struct linked_list *list, size_t value) {
  newNode = list_node(value);
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
     struct list_node *me = cur;
    
  }
  me.next = *newNode;
  
  
}

size_t remove_from_head(struct linked_list *list) { 
    struct list_node *cur = list.head; 
    struct list_node *me = cur -> next;
    free(cur);
    list.head = *me;
    

  }
                          }

size_t remove_from_tail(struct linked_list *list) { 
     newNode = list_node(value);
     int i = 0;
    struct list_node *tail = list.head;
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
     struct list_node *me = cur;
      if ( i > 0){
        tail = tail -> next;
      }
     i++;
  }
  free(me);
  tail->next = NULL;
  return 0;
  }

void free_list(struct linked_list list) {
  struct list_node* temp;              //Format taken from insumity from StackOverflow - rewritten by me for this assignment
                                       //I originally was writing it myself, but while researching to confirm I came across this and couldnt really forget it so I just cited it
   while (list.head != NULL)
    {
       tmp = list.head;
       head = head->next;
       free(tmp);
    }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
