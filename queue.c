#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"

void enqueue(struct queue *q, struct game_state state) {
  struct linked_list *data = q -> data;
  insert_at_tail(data, state);
 
}

struct game_state dequeue(struct queue *q) { 
  struct linked_list *data = q -> data;
 
  return remove_from_tail(data); 
}


int number_of_moves(struct game_state start) { 

  
  return 0; 
                                              
                                             }
