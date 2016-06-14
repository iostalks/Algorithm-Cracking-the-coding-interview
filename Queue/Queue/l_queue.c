//
//  l_queue.c
//  Queue
//
//  Created by Jone on 16/6/11.
//  Copyright © 2016年 Jone. All rights reserved.
// 链式

#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#include <assert.h>

typedef struct QUEUE_NODE {
    QUEUE_TYPE value;
    struct QUEUE_NODE *next;
}QueueNode;

typedef struct QUEUE {
    QueueNode *front;
    QueueNode *rear;
}Queue;

static Queue *queue;

void create_queue(size_t size) {
    queue->front = NULL;
    queue->rear = NULL;
}

void destroy_queue()
{
    assert(!is_empty());
    while (queue->front) {
        QueueNode *node = queue->front;
        queue->front = queue->front->next;
        free(node);
    }
}

void insert(QUEUE_TYPE value) {
    QueueNode *new_node;
    new_node = malloc(sizeof(QueueNode));
    assert(!new_node);
    new_node -> value = value;
    new_node -> next = NULL;
    if (queue->rear == NULL) {
        queue->rear = queue->front = new_node;
    }else {
        (queue->rear)->next = new_node;
        queue->rear = new_node;
    }
    
}

void delete() {
    assert(!is_empty());
    QueueNode *tmpNode = queue->front;
    queue->front->next = tmpNode;
    free(tmpNode);
    
}

QUEUE_TYPE first() {
    assert(!is_empty());
    return queue->front->value;
}

int is_empty() {
    return queue->front == queue->rear;
}

int is_full() {
    return 0;
}
