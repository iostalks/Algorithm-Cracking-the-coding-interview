//
//  main.cpp
//  Cracking1.4
//
//  Created by Jone on 16/4/8.
//  Copyright © 2016年 Jone. All rights reserved.
//

/**
 题目
 
 原文：
 
 Write a method to decide if two strings are anagrams or not.
 
 译文：
 
 写一个函数判断两个字符串是否是变位词。
 
 变位词(anagrams)指的是组成两个单词的字符相同，但位置不同的单词。比如说， abbcd和abcdb就是一对变位词。该题目有两种做法：
 */



#include <iostream>
#include <cstring>
using namespace std;

//O(nlogn)的解法
//
//由于组成变位词的字符是一模一样的，所以按照字典序排序后，两个字符串也就相等了。 因此我们可以用O(nlogn)的时间去排序，然后用O(n)的时间比较它们是否相等即可。
//
//代码如下：

bool isAnagram1(string s1, string s2)
{
    if (s1 == "" || s2 == "") return false;
    if (s1.length() != s2.length()) return false;
    
    /**
     *  sort() 排序函数，传入字符串的首位元素地址
     */
    sort(&s1[0], &s1[0] + s1.length());
    sort(&s2[0], &s2[0] + s2.length());
    
    if (s1 == s2) return true;
    else return  false;
}


//O(n)的解法
//
//由于组成变位词的字符是一模一样的， 因此我们可以先统计每个字符串中各个字符出现的次数， 然后看这两个字符串中各字符出现次数是否一样。
//如果是，则它们是一对变位词。 这需要开一个辅助数组来保存各字符的出现次数。
//我们可以开一个大小是256的整数数组， 遍历第一个字符串时，将相应字符出现的次数加1；
//遍历第二个字符串时， 将相应字符出现的次数减1。最后如果数组中256个数都为0，说明两个字符串是一对变位词。
//(第1个字符串中出现的字符都被第2个字符串出现的字符抵消了)， 如果数组中有一个不为0，说明它们不是一对变位词。

bool isAnagram2(string s1, string s2)
{
    if (s1 == "" || s2 == "") return false;
    if (s1.length() != s2.length()) return false;
    
    int len = (int)s1.length();
    int c[256] = {0};
    
    for (int i = 0; i < len; ++i)
    {
        c[(int)s1[i]] = c[(int)s1[i]] + 1;
        c[(int)s2[i]] = c[(int)s2[i]] - 1;
    }
    
    for (int i = 0; i < 256; ++i) {
        if (c[i] != 0) return false;
    }
    return true;
}



int main(int argc, const char * argv[]) {
    
    bool isAnagram1(string s1, string s2);
    bool isAnagram2(string s1, string s2);
    
    string s1 = "ababba";
    string s2 = "bbabaa";
    
    cout << isAnagram1(s1, s2) <<endl;
    cout << isAnagram2(s1, s2) <<endl;
    
    return 0;
}
