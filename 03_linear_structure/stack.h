//
// Created by jun on 2020/10/13.
//

#ifndef DACHENYUE_STACK_H
#define DACHENYUE_STACK_H

#include <iostream>

#define ERROR -1

typedef int Position;
typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType *Data;
    Position Top;
    int MaxSize;
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize);

bool IsFull(Stack S);

bool Push(Stack S, ElementType X);

bool IsEmpty(Stack S);

ElementType Pop(Stack S);

#endif //DACHENYUE_STACK_H
