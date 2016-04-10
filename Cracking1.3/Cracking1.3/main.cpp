//
//  main.cpp
//  Cracking1.3
//
//  Created by Jone on 16/4/7.
//  Copyright © 2016年 Jone. All rights reserved.
//

/*

原文：

Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

FOLLOW UP

Write the test cases for this method.

译文：
 
设计算法并写出代码移除字符串中重复的字符，不能使用额外的缓存空间。注意： 可以使用额外的一个或两个变量，但不允许额外再开一个数组拷贝。
 

*/

#include <iostream>
#include <cstring>
using namespace std;

/*
这道题目其实是要你就地(in place)将字符串中重复字符移除。你可以向面试官问清楚， 不能使用额外的一份数组拷贝是指根本就不允许开一个数组，还是说可以开一个固定大小， 与问题规模(即字符串长度)无关的数组。

如果根本就不允许你再开一个数组，只能用额外的一到两个变量。那么，你可以依次访问 这个数组的每个元素，每访问一个，就将该元素到字符串结尾的元素中相同的元素去掉( 比如置为’\0’).时间复杂度为O(n^2 )，代码如下：

*/
#pragma mark - 方法一

void removeDuplicate(char s[])
{
    int len = (int)strlen(s);
    if (len < 2) {
        return;
    }
    int p = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] != '\0')
        {
            s[p++] = s[i]; // 构建新值
            for (int j=i+1; j < len; ++j)
            {
                if (s[j] == s[i])
                    s[j] = '\0';
            }
        }
    }
    s[p] = '\0';
}
/*

如果可以开一个固定大小，与问题规模(即字符串长度)无关的数组，那么可以用一个数组来 表征每个字符的出现(假设是ASCII字符，则数组大小为256)，这样的话只需要遍历一遍字符 串即可，时间复杂度O(n)。代码如下：
*/

void removeDuplicate1(char s[])
{
    int len = (int)strlen(s);
    if (len < 2) return;
    
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (!c[s[i]]) {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';
}

// 只包含小写字母
void removeDuplicate2(char s[])
{
    int len = (int)strlen(s);
    if (len < 2) return;
    
    int check = 0, p = 0;
    for (int i = 0; i < len; ++i) {
        
        int v = s[i] - 'a';
        
        if ((check & (1 << v)) == 0) {
            s[p++] = s[i];
            check |= (1 << v);
        }
       
    }
    s[p] = '\0';
}


// 字符串
string removeDuplicateS(string s)
{
    int check = 0;
    int len = (int)s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v)) == 0)
        {
            str += s[i];
            check |= (1<<v);
        }
    }
    return str;
}

int main(int argc, const char * argv[]) {

    void removeDuplicate(char s[]);
    void removeDuplicate1(char s[]);
    void removeDuplicate2(char s[]);
    
    string removeDuplicateS(string s);
    
    char s1[] = "abcde";
    char s2[] = "aaabbb";
    char s3[] = "";
    string s4 = "abababc";
    
    
    removeDuplicate(s1);
    removeDuplicate1(s2);
    removeDuplicate2(s3);
    

    cout << s1 << " " << s2 << " " << s3 << endl;
    cout << removeDuplicateS(s4) << endl;

    return 0;
}
