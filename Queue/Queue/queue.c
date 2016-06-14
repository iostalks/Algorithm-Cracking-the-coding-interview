//
//  queue.c
//  Queue
//
//  Created by Jone on 16/6/11.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
#include <assert.h>


#define QUEUE_SIZEE 100
#define ARRAY_SIZE  (QUEUE_SIZEE + 1)

static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t     front = 1;
static size_t     rear  = 0;


void insert(QUEUE_TYPE value) {
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

void delete() {
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}

QUEUE_TYPE first() {
    assert(!is_empty());
    return queue[front];
}

int is_empty() {
    return (rear + 1) % ARRAY_SIZE == front;
}

int is_full() {
    return  (rear + 2) % ARRAY_SIZE == front;
}
