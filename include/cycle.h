#ifndef CYCLE_H
#define CYCLE_H
#include "phase.h"

typedef struct
{
    int count;
    int times;
    phase_t* head;
    phase_t* tail;
    phase_t* current;
} cycle_t;


cycle_t* make_cycle();
void del_cycle(cycle_t*);
void cycle_add_phase(cycle_t*, phase_t*);
void next_phase(cycle_t*);

#endif