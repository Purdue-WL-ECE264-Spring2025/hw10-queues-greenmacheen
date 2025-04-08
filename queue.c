#include "queue.h"
#include "tile_game.h"
#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


void enqueue(struct queue *q, struct game_state state) {

  insert_at_tail(&(q->data), serialize(state));
  
 
}

struct game_state dequeue(struct queue *q) { 
  
  return deserialize(remove_from_head(&(q->data))); 
}


int number_of_moves(struct game_state start) {
  struct queue *q =  (struct queue *)calloc(1,sizeof(struct queue));
  struct linked_list *list = (struct linked_list *)calloc(1,sizeof(struct linked_list));
  insert_at_tail(list, serialize(start));
  struct game_state up;
  struct game_state down;
  struct game_state left;
  struct game_state right;
  uint8_t tilecheck[4][4];
  int endNow = 0;
  int step = 1;
  q->data = *list;
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
    if(endNow > 14 || up.num_steps > 15) {
      free_list(q->data);
      free(list);
      free(q);
      return up.num_steps;
    }
    memcpy(&down, &up, sizeof(struct game_state)) ;
    memcpy(&left, &up, sizeof(struct game_state)) ;
    memcpy(&right, &up, sizeof(struct game_state)) ;
    step = up.num_steps;
    move_down(&down);
    move_left(&left);
    move_right(&right);
    
    
    if (right.num_steps != up.num_steps) {
        enqueue(q, right);
    }
    if (left.num_steps != up.num_steps) {
        enqueue(q, left);
    }
    if (down.num_steps != up.num_steps) {
       enqueue(q, down);
    }
    move_up(&up);
     if (step != up.num_steps) {
       enqueue(q, up);
    }

    //printf("Up:%d Down:%d Left:%d Right: %d\n", up.num_steps, down.num_steps, left.num_steps, right.num_steps);
    
    

    
    
  } 
 
  

                                              
                                             }
