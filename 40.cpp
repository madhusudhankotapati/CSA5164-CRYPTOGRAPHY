#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define STATE_SIZE 25  
#define LANE_SIZE 64   
#define CAPACITY_LANES 16 
int all_capacity_lanes_nonzero(uint64_t state[]) {
    for (int i = STATE_SIZE - CAPACITY_LANES; i < STATE_SIZE; i++) {
        if (state[i] == 0) {
            return 0;
        }
    }
    return 1;
}
void initialize_state(uint64_t state[]) {
    for (int i = 0; i < STATE_SIZE; i++) {
        if (i >= STATE_SIZE - CAPACITY_LANES) {
            state[i] = (uint64_t)rand() | 1; 
        } else {
            state[i] = 0;
        }
    }
}
void initialize_message_block(uint64_t P0[]) {
    for (int i = 0; i < STATE_SIZE; i++) {
        P0[i] = (uint64_t)rand() | 1; 
    }
}

int main() {
    srand(time(NULL));

    uint64_t state[STATE_SIZE];
    uint64_t P0[STATE_SIZE];
    int iterations = 0;

    initialize_state(state);
    initialize_message_block(P0);
    while (!all_capacity_lanes_nonzero(state)) {
        for (int i = 0; i < STATE_SIZE; i++) {
            state[i] ^= P0[i];
        }
        iterations++;
    }

    printf("Number of iterations required: %d\n", iterations);

    return 0;
}
