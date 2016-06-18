//
//  tree.c
//  Tree
//
//  Created by Jone on 16/6/14.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE   100
#define ARRAY_SIZE (TREE_SIZE+1)

static TREE_TYPE tree[ARRAY_SIZE];

static int
left_child(int current)
{
    return current * 2;
}

static int
right_child(int current)
{
    return current * 2 + 1;
}

void
insert(TREE_TYPE value)
{
    int current;
    
    /**
     *  确保值为非零，因为零用于未使用
     */
    assert( value != 0);
    
    /**
     *  根节点从第一个元素开始
     */
    current = 1;
    
    while(tree[current] != 0) {
        /**
         *  根据情况进去叶节点或右子树 why
         */
        if (value < tree[current]) {
            current = left_child(current);
        }else {
            assert(value != tree[current]);
            current = right_child(current);
        }
        assert(current < ARRAY_SIZE);
    }
}

// 查找
TREE_TYPE *
find(TREE_TYPE value) {
    int current = 1;
    while (current < ARRAY_SIZE && tree[current] != value) {
        if (value < tree[current]) {
            current = left_child(current);
        } else {
            current = right_child(current);
        }
    }
    
    if (current < ARRAY_SIZE) {
        return tree + current;
    } else {
        return 0;
    }
}

// 前序遍历
static void
do_pre_order_traverse(int current, void(*callback)(TREE_TYPE value)) {
    if (current < ARRAY_SIZE && tree[current] != 0) {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

void
pre_order_traverse(void (*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(1, callback);
}





