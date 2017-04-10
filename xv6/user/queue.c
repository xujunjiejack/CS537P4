//
// Created by junjie on 4/9/17.
//

#include "types.h"
#include "stat.h"
#include "x86.h"
#include "fcntl.h"
#include "queue.h"
#include "user.h"

static struct Node* new_node(int val)
{
    struct Node* n = malloc(sizeof(*n));
    if (!n) {
        printf(1, "oops, malloc in queue failed\n");
        exit();
    }
    n->value = val;
    n->next = NULL;
    return n;
}

int
queue_init(struct Queue* queue){
    queue->header = new_node(0);
    queue->tail = NULL;
    queue->itemCount = 0;
    return 1;
}

int
q_insert(struct Queue* queue, int pid){

    if (queue->itemCount == 0){
        queue->header->value = pid;
        queue->tail = queue->header;
        queue->itemCount ++;
        return 1;
    }
    if (queue->itemCount >= 1){
// printf(1, "inserting: %d ***** itemCount: %d  *** header: %d \n", getpid(), queue->itemCount, queue->header->value);
        queue->tail->next = new_node(pid);

        queue->tail = queue->tail->next;
        queue->itemCount ++;
        return 1;
    }

    return 0;
}

int
q_pop(struct Queue* queue){
    if (queue->itemCount == 0){
        return -1;
    }
    if (queue->itemCount == 1){
        queue->itemCount --;
        return queue->header->value;
    }
    printf(1, "popping: %d ***** itemCount: %d \n", getpid(), queue->itemCount);
    struct Node* poped_node = queue->header;
    queue->header = queue->header->next;
    int pid = poped_node->value;
    free(poped_node);
    queue->itemCount --;
    return pid;
}

static void
free_recur(struct Node* node){
    if (node ->next == NULL){
        free(node);
        return;
    }

    free_recur(node->next);
    free(node);
    return;
}

int
q_free(struct Queue* queue){

    free_recur(queue->header);
    free(queue);
    return 0;
}