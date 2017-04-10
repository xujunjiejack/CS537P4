
#include "types.h"
#include "user.h"
#include "stat.h"
#include "x86.h"
#include "fcntl.h"

void mutex_init(struct mutex* mtx){
    mtx->flag = 0;
    mtx->guard = 0;
    mtx->q = malloc(2*sizeof(struct Node*) + sizeof(int));
    queue_init(mtx->q);
}

void mutex_lock(struct mutex* mtx){
    while(xchg((volatile uint *) &mtx->guard, 1) != 0);
    if (mtx->flag == 0){
        mtx->flag = 1;
        mtx->guard = 0;
    }else {
        q_insert(mtx->q,getpid());
        setpark();
        mtx->guard = 0;
        park();
    }

}
void mutex_unlock(struct mutex* mtx){
    while(xchg((volatile uint *) &mtx->guard, 1) != 0);
    if (mtx->q->itemCount == 0){
        mtx->flag = 0;
    }else{
        unpark(q_pop(mtx->q));
    }

    mtx->guard = 0;
}