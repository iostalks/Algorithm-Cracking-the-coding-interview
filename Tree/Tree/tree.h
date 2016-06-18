//
//  tree.h
//  Tree
//
//  Created by Jone on 16/6/14.
//  Copyright © 2016年 Jone. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

#endif /* tree_h */
#define TREE_TYPE int

/**
 *  insert 向树中添加一个新值，新值必须原先树中不存在
 *
 *  @param value 被添加的值
 */
void insert(TREE_TYPE value);


TREE_TYPE *find(TREE_TYPE value);

/**
 *  执行树的前序遍历，它的参数是一个回调函数指针，它指向的函数将在树中处理每个节点被调用，节点的值将作为参数传递给这个函数
 *
 *  @param callback <#callback description#>
 */
void pre_order_traverse(void (*callback)(TREE_TYPE value));