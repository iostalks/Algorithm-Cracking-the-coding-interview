//
//  main.cpp
//  Cracking1.2
//
//  Created by Jone on 16/4/6.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    
    void reverse1(char *s);
    void reverse2(char *s);

    
    char c[] = "123";
    reverse1(c);
    cout << c << endl;
    
    char d[] = "123456cds";
    reverse2(d);
    cout << d << endl;
    
    return 0;
}

void swap(char &a, char &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}


#pragma mark - 方法一
void reverse1(char *s)
{
    if (!s) return;
    char *p = s, *q = s;
    while (*q) ++q;
    --q;
    while (p < q) {
        swap(*p++, *q--);
    }
}

#pragma mark - 方法二
void reverse2(char *s)
{
    if(!s) return;
    size_t n = strlen(s);
    
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
}

