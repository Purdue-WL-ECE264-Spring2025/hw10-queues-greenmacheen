#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"
#include <stdlib.h>


void enqueue(struct queue *q, struct game_state state) {
  
  insert_at_tail(&(q->data), serialize(state));
 
}

struct game_state dequeue(struct queue *q) { 
  
  return deserialize(remove_from_tail(&(q->data))); 
}


int number_of_moves(struct game_state start) { 
  struct queue *q =  (struct queue *)malloc(sizeof(struct queue));
  int up, down, right, left;
  uint8_t tilecheck[4][4];
  int endNow = 1;
  for ( int i = 0; i < 16; i++ ) {
      tilecheck[i / 4][ i % 4] = i + 1;
  }
  for ( int j = 0; j < 15; j++ ) {
      if (tilecheck[j/4][j%4] != state->tiles[j/4][j%4]) { 
        endNow++;
        j = 15;
      }
  }
  if(endNow == 1) {
    return game_state -> num_steps;
  }
  up = number_of_moves(move_up(&start));
  down = number_of_moves(move_down(&start));
  right = number_of_moves(move_right(&start));
  left = number_of_moves(move_left(&start));
  
  return up; 
                                              
                                             }
