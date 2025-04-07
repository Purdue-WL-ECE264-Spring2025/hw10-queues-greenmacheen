
#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"
#include <stdlib.h>
#include <string.h>


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
  int endNow = 0;
  //q->data.head = new_node(serialize(start));
  enqueue(q, start);
  while(true){
      endNow = 0;
    up = dequeue(q);
    for (int i = 0; i < 16; i++ ) {
        tilecheck[i / 4][ i % 4] = i + 1;
    }
    for ( int j = 0; j < 15; j++ ) {
        
        if (tilecheck[j/4][j%4] == up.tiles[j/4][j%4]) { 
            endNow++;
        }
    }
    if(endNow > 14 || up.num_steps > 9) {
      //free_list(q->data);
      free(q);
      return up.num_steps;
    }
    memcpy(&down, &up, sizeof(struct game_state)) ;
    memcpy(&left, &up, sizeof(struct game_state)) ;
    memcpy(&right, &up, sizeof(struct game_state)) ;
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
