
#ifndef CONDVAR_H
#define CONDVAR_H

struct condvar {
    int guard;
    struct Queue* q;
};

void cv_init(struct condvar* cv);
void cv_wait(struct condvar* cv, struct mutex* mtx);
void cv_signal(struct condvar* cv);
void cv_broadcast(struct condvar* cv);

#endif
