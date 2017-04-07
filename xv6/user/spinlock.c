//
// Created by junjie on 4/6/17.
#include "types.h"
#include "stat.h"
#include "x86.h"
#include "fcntl.h"
#include "spinlock.h"

void spin_init(struct spinlock* lk){
    lk->locked = 0;
}

void spin_lock(struct spinlock* lk){
    while(xchg(&lk->locked, 1) != 0);
}

void spin_unlock(struct spinlock* lk){
    lk->locked = 0;
}

