//
// Created by junjie on 4/5/17.
//

#include "types.h"
#include "stat.h"
#include "user.h"

//struct spinlock lock;

void add_sum(int* number){

    int i = 0;
    for (i = 1; i< 100000001; i++){
        //spin_lock(&lock);
        *number = *number + 1;
       // spin_unlock(&lock);
    }
    exit();
}

int main(){
    int sum = 0;
   // spin_init(&lock);
    thread_create((void(*)(void*))add_sum, &sum);
    thread_create((void(*)(void*))add_sum, &sum);
    thread_join();
    thread_join();


    printf(1, "The final sum is %d", sum);
    exit();
}