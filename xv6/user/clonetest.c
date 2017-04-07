#include "types.h"
#include "stat.h"
#include "user.h"
//
// Created by junjie on 4/1/17.
//

int fn(void* a){
    printf(1, "function running, printing %p, value %d \n", a ,*(int*)a);
    exit();
    return 1;
}

void part1(){
    int k = 128;

    int (*realfn)(void*) = fn;
    //(*realfn)(&k);

    int clone_pid;
    char* ustack;
    ustack = malloc(4096);
    clone_pid = clone((void (*)(void*))realfn, &k, (void*)ustack);

    printf(1, "%d", clone_pid);
    void * join_stack;
    int join_pid = join(&join_stack);

    if (clone_pid == join_pid){
        printf(1, "join returns the right pid\n");
    } else{
        printf(1, "Fail, join returns the wrong pid\n");
    }

    if ( (int) ustack == (int) join_stack){
        printf(1, "join returns the right stack\n");
    } else {
        printf(1, "Fail, join returns the wrong stack\n");
    }


    printf(1, "Clone test end\n");
    exit();
}

void part2(){
    int k = 128;
    thread_create((void (*)(void*))fn, &k);
    thread_join();

    printf(1, "Thread creating test end\n");
    exit();
}

int main(int argc, char** argv){
    part2();
    exit();
}