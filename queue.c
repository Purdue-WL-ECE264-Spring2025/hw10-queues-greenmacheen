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
    // Initialize queue properly
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->data = NULL; // Initialize the linked list
    
    // Create a way to track visited states
    // (This would require additional code to implement a visited set)
    
    // Initialize first state
    start.num_steps = 0; // Ensure steps start at 0
    enqueue(q, start);
    
    while (q->data != NULL) { // While queue is not empty
        struct game_state current = dequeue(q);
        
        // Check if current state is the goal state
        int is_goal = 1;
        for (int i = 0; i < 16; i++) {
            if (current.tiles[i/4][i%4] != (i + 1) % 16) { // Assuming 0 represents the empty tile
                is_goal = 0;
                break;
            }
        }
        
        if (is_goal) {
            free_list(q->data);
            free(q);
            return current.num_steps;
        }
        
        // Stop if too many steps
        if (current.num_steps >= 20) {
            continue;
        }
        
        // Try all four moves
        struct game_state next_states[4];
        next_states[0] = current;
        next_states[1] = current;
        next_states[2] = current;
        next_states[3] = current;
        
        int valid_up = move_up(&next_states[0]);
        int valid_down = move_down(&next_states[1]);
        int valid_left = move_left(&next_states[2]);
        int valid_right = move_right(&next_states[3]);
        
        // Add valid moves to queue (and increment steps)
        if (valid_up) {
            next_states[0].num_steps = current.num_steps + 1;
            // Check if we've seen this state before (requires additional code)
            enqueue(q, next_states[0]);
        }
        
        // Similar code for down, left, right...
        // [Add similar blocks for the other three directions]
    }
    
    // If we get here, no solution was found within 20 steps
    free_list(q->data);
    free(q);
    return -1; // Indicate no solution found
}
/*int number_of_moves(struct game_state start) { 
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
    
  } */
 
  

                                              
                                             }
