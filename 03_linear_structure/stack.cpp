//
// Created by jun on 2020/10/13.
//

#include "stack.h"

Stack CreateStack(int MaxSize) {
    auto S = (Stack) malloc(sizeof(struct SNode));
    S->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S) {
    return (S->Top == S->MaxSize - 1);
}


bool Push(Stack S, ElementType X) {
    if (IsFull(S)) {
        printf("堆满\n");
        return false;
    } else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}


bool IsEmpty(Stack S) {
    return (S->Top == -1);
}

ElementType Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("堆空\n");
        return ERROR;
    } else return (S->Data[(S->Top)--]);
}
