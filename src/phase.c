#include "phase.h"

phase_t* make_phase(const char* name, int seconds)
{
    phase_t* p = malloc(sizeof(phase_t));
    if(!p) return NULL;
    p->name = malloc(strlen(name) + 1);
    if(!p->name){
        free(p);
        return NULL;
    }
    strcpy(p->name, name);
    p->seconds = seconds;
    p->next = NULL;
    return p;
}

void del_phase(phase_t* p)
{
    free(p->name);
    if(p->next){
        del_phase(p->next);
    }
    free(p);
}