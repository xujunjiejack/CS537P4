
#include "types.h"
#include "user.h"

int thread_create(void (*fn)(void*), void* arg){
    // spin_lock(ulock);
    //int * pid = malloc(4);
    char* ustack = malloc(4096);

    if (ustack == NULL){
        printf(1, "No enough memory");
        return -1;
    }
    int pid = clone(fn, arg, (void*)ustack);
    return pid;

}

int thread_join(void){
    void* ustack;
    int pid = join(&ustack);
    free(ustack);

    return pid;
}