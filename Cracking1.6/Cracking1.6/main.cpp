//
//  main.cpp
//  Cracking1.6
//
//  Created by Jone on 16/4/10.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;


/*
题目

原文：

Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

译文：

一张图像表示成NxN的矩阵，图像中每个像素是4个字节，写一个函数把图像旋转90度。 你能原地进行操作吗？(即不开辟额外的存储空间)

*/

/*
 解答
 
 我们假设要将图像逆时针旋转90度，顺时针是一个道理。如果原图如下所示：
 
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16
 那么逆时针旋转90度后的图应该是：
 
 4 8 12 16
 3 7 11 15
 2 6 10 14
 1 5 9 13
 我们要如何原地进行操作以达到上面的效果呢？可以分两步走。 第一步交换主对角线两侧的对称元素，第二步交换第i行和第n-1-i行，即得到结果。 看图示：
 
 原图：           第一步操作后：	第二步操作后：
 01 02 03 04 	01 05 09 13		04 08 12 16
 05 06 07 08 	02 06 10 14		03 07 11 15
 09 10 11 12    03 07 11 15     02 06 10 14
 13 14 15 16	04 08 12 16		01 05 09 13
 
*/

void swap(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

void transport(int a[][4], int n)
{
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    
    for (int i=0; i<n/2; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            swap(a[i][j], a[n-i-1][j]);
        }
    }
    
    
}

int main(int argc, const char * argv[]) {
    
//    void swap(int &a, int &b);
    void transport(int a[][4], int n);
    
    
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<endl;
    
    transport(a, 4);
    
    
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
