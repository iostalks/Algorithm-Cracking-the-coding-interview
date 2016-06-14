//
//  main.cpp
//  SortAlgorithm
//
//  Created by Jone on 16/5/9.
//  Copyright © 2016年 Jone. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    void printArr(int a[], int n);
    
    void popupSort(int a[], int n);
    void selectSort(int a[], int n);
    void inserSort(int a[], int n);
    void quickSort(int a[], int left, int right);
    
    
    int sortArr[] = {12, 9, 8, 5, 2, 4};
//    popupSort(popupSortArr, 6);
//    selectSort(sortArr, 6);
//    inserSort(sortArr, 6);
    quickSort(sortArr, 0, 5);
    
    printArr(sortArr, 6);
    
    
    void swapNumber(int &a, int &b);
    int a = 5, b = 6;
    
    swapNumber(a, b);
    printf("a=%d, b=%d\n",a,b);
    return 0;
}


// 冒泡排序
void popupSort(int a[], int n)
{
    void swapElement(int arr[], int i, int j);
    
    if (a==NULL || n <= 0) return;
    for (int i=0; i<n-1; ++i)
    {
        for (int j=n-1; j>i; --j)
        {
            if (a[j] < a[j-1])
            {
                swapElement(a, j-1, j);
            }
        }
    }
    
}

// 选择排序
void selectSort(int a[], int n)
{
    void swapElement(int arr[], int i, int j);
    if (a==NULL || n<=0) return;
    
    for (int i=0; i<n-1; ++i)
    {
        int min = i;
        for (int j=i+1; j<n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        
        if (min != i)
            swapElement(a, i, min);
    }
}

// 插入排序
void inserSort(int a[], int n)
{
    void swapElement(int arr[], int i, int j);
    if (a==NULL || n<=0) return;

    for (int i=1; i<n; ++i) {
        
        int j=i;
        int target = a[i];
        
        while (j>0 && target < a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        
        a[j] = target;
    }
}

// 快速排序 O（n*lgn）
int parrttion(int a[], int left, int right)
{
    if (a == NULL && left >= right) return NULL;
    
    void swapElement(int arr[], int i, int j);
    
    int pivotKey = a[left];
//    int pivotPointer = left;
    
    while (left < right) {
        while (left < right && a[right] >= pivotKey) {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= pivotKey) {
            left++;
        }
        a[right] = a[left];
        
//            swapElement(a, left, right);
    }
    
    a[left] = pivotKey;
    
//    swapElement(a, pivotPointer, left);
    return left;
}

void quickSort(int a[], int left, int right)
{

    if (left >= right) {
        return;
    }
    
    int parr = parrttion(a, left, right);
    quickSort(a, left, parr-1);
    quickSort(a, parr+1, right);
    
}
// 堆排序
void swapNumber(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}


// 希尔排序


// 归并排序


// 计数排序


// 桶排序


// 基数排序


#pragma mark - help


void swapElement(int arr[], int i, int j)
{
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void printArr(int a[], int n)
{
    for(int i=0; i<n; ++i)
    {
        printf("%d ", a[i]);
    }
    cout<<endl;
}