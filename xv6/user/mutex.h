
#ifndef MUTEX_H
#define MUTEX_H

struct mutex{
    int flag;
    int guard;
    struct Queue* q;
};

void mutex_init(struct mutex* mtx);
void mutex_lock(struct mutex* mtx);
void mutex_unlock(struct mutex* mtx);


#endif
