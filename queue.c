#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"
#include <stdlib.h>


void enqueue(struct queue *q, struct game_state state) {
  
  insert_at_head(&(q->data), serialize(state));
 
}

struct game_state dequeue(struct queue *q) { 
  
  return deserialize(remove_from_head(&(q->data))); 
}


int number_of_moves(struct game_state start) { 
  struct queue *q =  (struct queue *)malloc(sizeof(struct queue));
  struct game_state up;
  struct game_state down;
  struct game_state left;
  struct game_state right;
  uint8_t tilecheck[4][4];
  int endNow = 1;
  enqueue(q, start);
  while(true){
    up = dequeue(q);
    for (int i = 0; i < 16; i++ ) {
        tilecheck[i / 4][ i % 4] = i + 1;
    }
    for ( int j = 0; j < 15; j++ ) {
        if (tilecheck[j/4][j%4] != up.tiles[j/4][j%4]) { 
            endNow++;
          j = 15;
        }
    }
    if(endNow == 1 || up.num_steps > 20) {
      free_list(q->data);
       free(q);
      return up.num_steps;
    }
    down = up;
    left = up;
    right = up;
    move_up(&up);
    move_down(&down);
    move_left(&left);
    move_right(&right);
    enqueue(q, up);
    enqueue(q, down);
    enqueue(q, left);
    enqueue(q, right);
    
  }
 
  

                                              
                                             }
