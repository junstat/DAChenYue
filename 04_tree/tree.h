//
// Created by jun on 2020/10/13.
//

#ifndef DACHENYUE_TREE_H
#define DACHENYUE_TREE_H

#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

#endif //DACHENYUE_TREE_H
