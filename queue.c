#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"

void enqueue(struct queue *q, struct game_state state) {
  
  insert_at_tail(q->data, serialize(state));
 
}

struct game_state dequeue(struct queue *q) { 
  
  return (struct game_state)remove_from_tail(q->data); 
}


int number_of_moves(struct game_state start) { 

  
  return 0; 
                                              
                                             }
