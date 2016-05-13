//
//  main.cpp
//  Cracking3.1
//
//  Created by Jone on 16/5/5.
//  Copyright © 2016年 Jone. All rights reserved.
//


/**
 *  题目
 
 原文：
 
 Describe how you could use a single array to implement three stacks.
 
 译文：
 
 你如何只用一个数组实现三个栈？
 */


#include <iostream>
#include "string.h"
using namespace std;

/// 我们可以很容易地用一个数组来实现一个栈，压栈就往数组里插入值，栈顶指针加1； 出栈就直接将栈顶指针减1；取栈顶值就把栈顶指针指向的单元的值返回； 判断是否为空就直接看栈顶指针是否为-1。

 /// 如果要在一个数组里实现3个栈，可以将该数组分为3个部分。如果我们并不知道哪个栈将装 入更多的数据，就直接将这个数组平均分为3个部分，每个部分维护一个栈顶指针， 根据具体是对哪个栈进行操作，用栈顶指针去加上相应的偏移量即可。

/// 代码如下：
class stack3
{
public:
    stack3(int size = 300) {
        buf = new int[size * 3];
        ptop[0] = ptop[1] = ptop[2] = -1;
        this->size = size;
    }
    
    ~stack3(){
        delete buf;
    }
    
    void push(int stackNum, int val) {
        int idx = stackNum*size + ptop[stackNum]+1;
        buf[idx] = val;
        ++ptop[stackNum];
    }
    
    void pop(int stackNum){
        --ptop[stackNum];
    }
    
    int top(int stackNum){
        int idx = stackNum*size + ptop[stackNum];
        return buf[idx];
    }
    
    bool empty(int stackNum) {
        return ptop[stackNum] == -1;
    }
    
private:
    int *buf;
    int ptop[3];
    int size;
};


class stack33 {
private:
    int *buff;
    int ptop[3];
    int size;
    
public:
    stack33(int size){
        buff = new int[size * 3];
        ptop[0] = ptop[1] = ptop[2] = -1;
        this -> size = size;
    }
    
    
    void push(int stackNum, int val) {
        int idx = stackNum * size + ptop[stackNum] + 1;
        buff[idx] = val;
        ++ptop[stackNum];
    }
    
    
};
typedef struct node {
    int val, preIdx;
}node;

class stack3_1 {
public:
    stack3_1(int totalSize = 900) {
        buf = new node[totalSize];
        ptop[0] = ptop[1] = ptop[2] = -1;
        this -> totalSize = totalSize;
        cur = 0;
    }
    
    ~ stack3_1() {
        delete buf;
    }
    
    void push(int stackNum, int val) {
        buf[cur].val = val;
        buf[cur].preIdx = ptop[stackNum];
        ptop[stackNum] = cur;
        ++cur;
    }
    
    void pop(int stackNum){
        ptop[stackNum] = buf[ptop[stackNum]].preIdx;
    }
    
    int top(int stackNum){
        return buf[ptop[stackNum]].val;
    }
    bool empty(int stackNum){
        return ptop[stackNum]==-1;
    }

    
private:
    node *buf;
    int ptop[3];
    int totalSize;
    int cur;
};


int main(int argc, const char * argv[]) {
    
    
//    stack3_1 mystack;
    stack3 mystack;
    for(int i=0; i<10; ++i)
        mystack.push(0, i);
    for(int i=10; i<20; ++i)
        mystack.push(1, i);
    for(int i=100; i<110; ++i)
        mystack.push(2, i);
    for(int i=0; i<3; ++i)
        cout<<mystack.top(i)<<" ";
    
    cout<<endl;
    for(int i=0; i<3; ++i){
        mystack.pop(i);
        cout<<mystack.top(i)<<" ";
    }
    
    cout <<endl;
    
    mystack.push(0, 111);
    mystack.push(1, 222);
    mystack.push(2, 333);
    for(int i=0; i<3; ++i)
        cout<<mystack.top(i)<<" ";
    cout<<endl;
    return 0;
}
