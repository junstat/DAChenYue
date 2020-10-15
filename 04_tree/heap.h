//
// Created by jun on 2020/10/15.
//

#ifndef DACHENYUE_HEAP_H
#define DACHENYUE_HEAP_H

#include <iostream>
#include <climits>
using namespace std;

#define MaxData INT_MAX

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements;      /* 存储堆元素的数组 */
    int Size;       /* 堆的当前元素个数 */
    int Capacity;   /* 堆的最大容量 */
};


MaxHeap Create(int MaxSize);

bool IsFull(MaxHeap H);

bool IsEmpty(MaxHeap H);

void Insert(MaxHeap H, ElementType item);

ElementType DeleteMax(MaxHeap H);

#endif //DACHENYUE_HEAP_H
