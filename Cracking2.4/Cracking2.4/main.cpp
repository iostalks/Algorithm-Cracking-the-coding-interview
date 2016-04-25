//
//  main.cpp
//  Cracking2.4
//
//  Created by Jone on 16/4/25.
//  Copyright © 2016年 Jone. All rights reserved.
//
// 两个数相加，513 + 295
/**
 *  原文：
 
 You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
 
 EXAMPLE
 
 Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
 
 Output: 8 -> 0 -> 8
 
 译文：
 
 你有两个由单链表表示的数。每个结点代表其中的一位数字。数字的存储是逆序的， 也就是说个位位于链表的表头。写一函数使这两个数相加并返回结果，结果也由链表表示。
 
 例子：(3 -> 1 -> 5), (5 -> 9 -> 2)
 
 输入：8 -> 0 -> 8
 */

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/**
 *  这道题目并不难，需要注意的有：1.链表为空。2.有进位。3.链表长度不一样。 代码如下
 */

typedef struct node {
    int data;
    node *next;
}node;

node* init(int a[], int n)
{
    node *head = nullptr, *p = nullptr;
    for (int i=0; i<n; ++i) {
        node *nd = new node();
        nd->data = a[i];
        if (i==0) {
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}


node* addlink(node *p, node *q)
{
    if (p==NULL) return q;
    if (q==NULL) return p;
    node *res = nullptr, *pre = nullptr;
    int c=0;
    while (q && p) {
        int t = p->data + q->data + c;
        node *r = new node();
        r->data = t%10;
        if (pre) {
            pre -> next = r;
            pre = r;
        }else {
            pre = res = r;
        }
        
        c = t/10;
        p = p -> next;
        q = q -> next;
    }
    
    while (p)
    {
        int t = p->data + c;
        node *r = new node();
        r->data = t%10;
        pre->next = r;
        pre = r;
        c = t/10;
        p = p->next;
    }
    
    while (q)
    {
        int t = q->data + c;
        node *r = new node();
        r -> data = t%10;
        pre -> next = r;
        pre = r;
        c = t/10;
        q = q -> next;
    }
    
    if(c>0){//当链表一样长，而又有进位时
        node *r = new node();
        r->data = c;
        pre->next = r;
    }
    
    return res;
}

void print(node *head)
{
    while (head) {
        int d = head -> data;
        cout << d << " ";
        head = head -> next;
        
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    node* addlink(node *p, node *q);
    void print(node *head);
    int n = 4;
    int a[] = {
        1, 2, 9, 3
    };
    int m = 3;
    int b[] = {
        9, 9, 2
    };
    
    node *p = init(a, n);
    node *q = init(b, m);
    node *res = addlink(p, q);
    if(p) print(p);
    if(q) print(q);
    if(res) print(res);
    return 0;
}
