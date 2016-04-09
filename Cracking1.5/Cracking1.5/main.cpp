//
//  main.cpp
//  Cracking1.5
//
//  Created by Jone on 16/4/8.
//  Copyright © 2016年 Jone. All rights reserved.
//

/*
 题目
 
 原文：
 
 Write a method to replace all spaces in a string with ‘%20’.
 
 译文：
 
 写一个函数，把字符串中所有的空格替换为%20 。
 
 */

#include <iostream>
#include <cstring>
using namespace std;

/*
 先遍历一次字符串，得到空格个数，进而得到将空格转换成%20后的串长度 (每个空格替换为%20需要增加2个字符，x个空格增加2x个字符)。 
 然后从后向前依次对空格进行替换，非空格原样拷贝。
 如果原串有足够大的空间， 则替换过程直接在原串上进行， 因为从后向前替换的过程中，新串用到的空间一定是旧串不需要的空间
*/


char* replaceWhiteSpace(char *c)
{
    if (c == NULL) return NULL;
    int len = (int)strlen(c);
    if (len == 0) return NULL;
    int cnt = 0;
    for (int i=0; i<len; ++i)
    {
        if (c[i] == ' ')
            ++cnt;
    }
    
    char *nc = new char[len + 2*cnt + 1];
    int p = 0;
    for (int i=0; i<len; ++i) {
        if (c[i] == ' ') {
            nc[p] = '%';
            nc[p+1] = '2';
            nc[p+2] = '0';
            p += 3;
        }
        else {
            nc[p] = c[i];
            ++p;
        }
    }
    
//    printf("%d\n",(int)strlen(c));
    nc[p] = '\0';

    return nc;
}


void replaceWhiteSpace1(char *c)
{
    if (c == NULL) return;
    int len = (int)strlen(c);
    if (len == 0) return;
    int cnt = 0;
    for (int i=0; i<len; ++i)
    {
        if (c[i] == ' ')
            ++cnt;
    }
    
    int p = len + 2 * cnt;
    c[p--] = '\0'; //the space must be allocated first.
    for (int i=len-1; i>0; --i) {
        if (c[i] == ' ') {
            c[p] = '0';
            c[p-1] = '2';
            c[p-2] = '%';
            
            p -= 3;
        }else {
            c[p] = c[i];
            --p;
        }
    }
    
}

int main(int argc, const char * argv[])
{
    char* replaceWhiteSpace(char *c);
    void replaceWhiteSpace1(char *c);
    
    char c[100] = "I am Programmer";
    
    cout << replaceWhiteSpace(c) << endl;
    
    replaceWhiteSpace1(c);
    cout << c << endl;
    
    return 0;
}







