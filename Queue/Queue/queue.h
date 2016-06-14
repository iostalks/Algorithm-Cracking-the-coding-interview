//
//  queue.h
//  Queue
//
//  Created by Jone on 16/6/11.
//  Copyright © 2016年 Jone. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

#endif /* queue_h */



#define QUEUE_TYPE int

void create_queue(size_t size);

void destroy_queue();

void insert(QUEUE_TYPE value);

void delete();

QUEUE_TYPE first();

int is_empty();

int is_full();

