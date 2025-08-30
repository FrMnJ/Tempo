#ifndef PHASE_H
#define PHASE_H
#include <string.h>
#include <stdlib.h>

typedef struct phase_t
{
    char* name;
    int seconds;
    struct phase_t* next;
} phase_t;

phase_t* make_phase(const char*, int);
void del_phase(phase_t*);

#endif