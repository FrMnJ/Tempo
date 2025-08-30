#include "cycle.h"

cycle_t* make_cycle()
{
    cycle_t* c = malloc(sizeof(cycle_t));
    if(!c) return NULL;
    c->count = 0;
    c->times = 0;
    c->head = NULL;
    c->tail = NULL;
    return c;
}

void del_cycle(cycle_t* c)
{
    c->count = 0;
    c->tail->next = NULL;
    del_phase(c->head);
    free(c);
}

void cycle_add_phase(cycle_t* c, phase_t* p)
{
    if(!c->tail)
    {
        c->head = p;
        c->tail = p;
        p->next = p;
        c->current = p;
    }
    else
    {
        c->tail->next = p;
        c->tail = p;
        p->next = c->head;
    }
    c->count++;
}

void next_phase(cycle_t* c){
    c->current = c->current->next;
    if(c->current == c->head){
        c->times--;
    }
    if(c->times == 0){
        c->current = NULL;
    }
}