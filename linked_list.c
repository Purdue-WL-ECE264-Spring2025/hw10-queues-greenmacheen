#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
  struct list_node *newNode = (struct list_node*) malloc( sizeof( struct list_node ) );
  newNode->value = value;
  return newNode;
}

void insert_at_head(struct linked_list *list, size_t value) {
    if (list == NULL) {
        fprintf(stderr, "Error: list is NULL\n");
        return;
    }

    struct list_node *newNode = new_node(value);
    if (newNode == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for newNode\n");
        return;
    }

    newNode->next = list->head;
    list->head = newNode;
}

void insert_at_tail(struct linked_list *list, size_t value) {
    // Create a new node
    struct list_node *newNode = new_node(value);
    if (newNode == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for new node\n");
        return;
    }

    // Check if the list itself is NULL
    if (list == NULL) {
        fprintf(stderr, "Error: The list is NULL\n");
        free(newNode); // Free the new node to avoid memory leak
        return;
    }

    // Handle empty list case
    if (list->head == NULL) {
        list->head = newNode; // Set the new node as the head of the list
        return;
    }

    // Traverse to the tail of the list
    struct list_node *cur = list->head;
    while (cur != NULL && cur->next != NULL) { // Check cur before accessing cur->next
        cur = cur->next; // Move to the next node
    }

    // Append the new node to the tail
    if (cur != NULL) {
        cur->next = newNode;
    }
}

size_t remove_from_head(struct linked_list *list) {
    
    struct list_node *cur = list->head;
    size_t value = cur->value;
    
    list->head = cur->next;
    

    free(cur);
    
   
    return value;
}                 

/*size_t remove_from_tail(struct linked_list *list) {
     struct list_node *me = list->head;
     int i = 0;
    struct list_node *tail = list->head;
  for (struct list_node *cur = list->head; cur != NULL; cur = cur->next) {
     me = cur;
      if ( i > 0){
        tail = tail -> next;
      }
     i++;
  }
  free(me);
  tail->next = NULL;
  return 0;
  }*/
size_t remove_from_tail(struct linked_list *list) {
    if (list->head == NULL) {
        return -1; // Handle empty list
    }

    if (list->head->next == NULL) { // Single node list
        size_t removedValue = list->head->value;
        free(list->head);
        list->head = NULL;
        return removedValue;
    }
   int step = 0;
   struct list_node *me;
   struct list_node *cur;
   cur = list->head; 
   if (cur != NULL) {
   
    while (cur->next != NULL)  {
     me = cur;
     cur = cur -> next;
     step++;
     printf("step: %d\n", step);
   }
   }

    // 'current' is now the tail node, and 'prev' is the second-to-last node
    size_t removedValue = cur->value;
    free(cur);
    me->next = NULL;
    return removedValue;
}
void free_list(struct linked_list list) {  // Changed to pointer
    struct list_node *current = list.head;
    struct list_node *next;
    
    while (current != NULL) {
        next = current->next;  // Save next pointer before freeing
        free(current);
        current = next;
    }
    
    list.head = NULL;  // Set head to NULL to indicate empty list
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
