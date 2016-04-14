//
//  main.cpp
//  Cracking1.8
//
//  Created by Jone on 16/4/12.
//  Copyright © 2016年 Jone. All rights reserved.
// http://www.hawstein.com/posts/1.8.html

/**
 *  题目
 
 原文：
 
 Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”).
 
 译文：
 
 假设你有一个 isSubstring 函数，可以检测一个字符串是否是另一个字符串的子串。 给出字符串s1和s2，只使用一次isSubstring就能判断s2是否是s1的旋转字符串， 请写出代码。旋转字符串：”waterbottle”是”erbottlewat”的旋转字符串。
 *
 */


#include <iostream>
#include <cstring>
using namespace std;

bool isSubstring(string s1, string s2){
    if(s1.find(s2) != string::npos) return true;
    else return false;
}

bool isRotation(string s1, string s2){
    if(s1.length() != s2.length() || s1.length()<=0)
        return false;
    return isSubstring(s1+s1, s2);
}


int main(int argc, const char * argv[]) {
    
    string s1 = "apple";
    string s2 = "pleap";
    cout<<isRotation(s1, s2)<<endl;
    
    return 0;
}
