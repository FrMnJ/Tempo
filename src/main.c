#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "tempo_errors.h"
#include "cycle.h"

static char input[2048];

int main(int argc, char** argv)
{
    int phases;
    printf("Enter the number of phases in your cycle: ");
    scanf("%d", &phases);
    if(phases < 1) return INVALID_NUM_PHASES_ERR;
    while(getchar() != '\n');
    cycle_t* my_cycle = make_cycle();
    if(!my_cycle){
        return CYCLE_MEM_ERR;
    }
    for(int i = 0; i < phases; i++){
        printf("Enter a name for phase %d: ",(i+1));
        fgets(input, 2048, stdin);

        int seconds;
        printf("Enter the duration of this phase in seconds (positive integer): ");
        scanf("%i", &seconds);
        if(seconds < 1) return INVALID_DUR_ERR;
        while(getchar() != '\n');
        input[(strlen(input)-1)] = '\0';
        phase_t* new_phase = make_phase(input, seconds);
        if(!new_phase){
            return PHASE_MEM_ERR;
        }
        cycle_add_phase(my_cycle, new_phase);
    }
    int times;
    printf("Enter how many times the entire cycle should repeat: ");
    scanf("%i", &times);
    if(times < 1) return INVALID_TIMES_CYCLE_ERR;
    while(getchar() != '\n');
    my_cycle->times = times;
    int waitfor;
    printf("Enter how much time I need to wait for the start: ");
    scanf("%d", &waitfor);
    while(getchar() != '\n');
    if(waitfor < 0) waitfor = 5;
    #ifdef _WIN32
        Sleep(waitfor*1000);
        Beep(750, 1000);
    #else
        sleep(waitfor);
        printf("\a");
    #endif
    while(my_cycle->current){
        printf("Phase: %s\n", my_cycle->current->name);
        printf("Time in seconds: %d\n", my_cycle->current->seconds);
        #ifdef _WIN32
            Sleep(my_cycle->current->seconds*1000);
            Beep(750, 500);
        #else
            sleep(my_cycle->current->seconds);
            printf("\a");
        #endif
        next_phase(my_cycle);
    }
    del_cycle(my_cycle);
    #ifdef _WIN32
        Beep(750, 1500);
    #else
        printf("\a");
        printf("\a");
    #endif
    printf("END\n");
    return 0;
}