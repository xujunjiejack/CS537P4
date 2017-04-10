//
// Created by junjie on 4/9/17.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


struct Node {
    int value;
    struct Node* next;
};

struct Queue{
    struct Node* header;
    struct Node* tail;
    int itemCount;
};

int
queue_init(struct Queue* queue);
int
q_insert(struct Queue* queue, int pid);

#endif //QUEUE_QUEUE_H
