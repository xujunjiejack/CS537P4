//
// Created by junjie on 4/6/17.
//

#ifndef SPINLOCK_H
#define SPINLOCK_H

struct spinlock{
    volatile uint locked;
};
void spin_init(struct spinlock* lk);
void spin_lock(struct spinlock* lk);
void spin_unlock(struct spinlock* lk);

#endif //CS537P4_SPINLOCK_H
