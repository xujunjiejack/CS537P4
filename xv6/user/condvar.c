
#include "types.h"
#include "user.h"
#include "x86.h"
#include "condvar.h"

void cv_init(struct condvar* cv)
{
    cv->q = malloc(2*sizeof(struct Node*) + sizeof(int));
    queue_init(cv->q);
    cv->guard = 0;
}

void cv_wait(struct condvar* cv, struct mutex* mtx)
{
	/* fill this in! */
    // guard the lock
    while(xchg((volatile uint *) &cv->guard, 1) != 0);
    setpark();
    if (cv->q->tail->value != getpid()) {
        q_insert(cv->q, getpid());
    }
    mutex_unlock(mtx);
    cv->guard = 0;
    park();
}

void cv_signal(struct condvar* cv)
{
	/* fill this in! */
    while(xchg((volatile uint *) &cv->guard, 1) != 0);
    if (cv->q->itemCount == 0){

    } else {
        unpark(q_pop(cv->q));
    }
    cv->guard = 0;
}

void cv_broadcast(struct condvar* cv)
{
	/* fill this in! */
}
