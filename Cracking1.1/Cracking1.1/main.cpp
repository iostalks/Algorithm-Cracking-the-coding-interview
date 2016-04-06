//
//  main.cpp
//  Cracking1.1
//
//  Created by Jone on 16/4/6.
//  Copyright © 2016年 Jone. All rights reserved.
//

/*
原文：
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

译文：
实现一个算法来判断一个字符串中的字符是否唯一(即没有重复).不能使用额外的数据结构。 (即只使用基本的数据结构)

 */

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
  
    bool isUnique1(string s);
    bool isUnique2(string s);
    bool isUnique3(string s);
    
    string s1 = "I am ";
    string s2 = "no'dif ";
    cout << isUnique1(s1) << endl;
    
//    cout << isUnique2(s2) << endl;
//    cout << isUnique3(s3) << endl;
    
    
    return 0;
}

#pragma mark - 情况二：ASCII字符

// __________________________________

// 如果我们假设字符集是ASCII字符，那么我们可以开一个大小为256的bool数组来表征每个字 符的出现。
// 数组初始化为false，遍历一遍字符串中的字符，当bool数组对应位置的值为真，
// 表明该字符在之前已经出现过，即可得出该字符串中有重复字符。否则将该位置的bool数组 值置为true。
// 该算法的时间复杂度为O(n)

bool isUnique1(string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));
    int len = (int)s.length();
    for (int i = 0; i < len; i++) {
        int v = (int)s[i];
        if (a[v]) return false;
        a[v] = true;
    }
    return true;
}


// 我们还可以通过位运算来减少空间的使用量。 用每一位表征相应位置字符的出现。
// 对于ASCII字符，我们需要256位，即一个长度为8的int数组a即可。这里的关键是要把字符对应的数字，映射到正确的位上去。
// 比如字符’b’对应的 代码是98，那么我们应该将数组中的哪一位置为1呢？用98除以32，得到对应数组a的下标： 3。98对32取模得到相应的位：2

bool isUnique2(string s)
{
    int a[8];
    memset(a, 0, sizeof(a));
    int len = (int)s.length();
    for (int i = 0; i < len; i++) {
        int v = (int)s[i];
        int idx = v / 32, shift = v % 32;
        if (a[idx] & (1 << shift)) return false;
        a[idx] = a[idx] | (1 << shift);
    }
    
    return true;
}

#pragma mark - 情况二：26个字母
// __________________________________

bool isUnique3(string s)
{
    int check = 0;
    int len = (int)s.length();
    for (int i = 0; i < len; i++) {
        int v = (int)(s[i] - 'a');
        if (check & (1 << v)) {
            return false;
        }
        check |= (1 << v);
    }
    return true;
}

/**
 *  十进制转二进制输出
 *
 *  @param
 */

void printBinary(int a)
{
    for (int i = 31; i >= 0; i--) {
        if (a & (1 << i)) {
            cout << 1;
        }else {
            cout << 0;
        }
        
        if (i % 4 == 0) {
            cout << " ";
        }
    }
}



