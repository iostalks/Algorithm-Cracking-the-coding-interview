//
//  l_tree.c
//  Tree
//
//  Created by Jone on 16/6/16.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
typedef struct TREE_NODE {
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;


/**
 *  指向根节点的指针
 *
 */

static TreeNode *tree;

void insert(TREE_TYPE value) {
    TreeNode *current;
    TreeNode **link;
    
    link = &tree;
    
    while ((current = *link) != NULL) {
        if (value < current->value) {
            link = &current->left;
        }else {
            assert(value != current->value);
            link = &current->right;
        }
    }
    
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

TREE_TYPE *find(TREE_TYPE value) {
    TreeNode *current;
    current = tree;
    while (current -> value != value && current != NULL) {
        if (value < current->value) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    
    if (current != NULL) {
        return &current->value;
    }else {
        return NULL;
    }
}

void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value)) {
    if (current != NULL) {
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
    do_pre_order_traverse(tree, callback);
}

// 后序遍历

void destroy_tree(TreeNode *node) {
    if (node == NULL) return;
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
}

// 计算树的深度
int depth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    
    return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}


#define TRUE 1
#define FALSE 0

// 判断是否为平衡树--左右子树深度差小于1
int is_balanceTree(TreeNode *root) {
    if (root == NULL) return TRUE;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    if (abs(leftDepth-rightDepth) > 1) return FALSE;
    
    return is_balanceTree(root->left) && is_balanceTree(root->right);
}

int is_balanceTree2(TreeNode *root, int *depth) {
    if (root == NULL) {
        *depth = 0;
        return TRUE;
    }
    
    int left, right;
    if (is_balanceTree2(root->left, &left) && (is_balanceTree2(root->right, &right))) {
        int diff = left - right;
        if (abs(diff) <= 1) {
            *depth = 1 + (left > right ? left : right);
            return TRUE;
        }
    }
    return FALSE;
}





