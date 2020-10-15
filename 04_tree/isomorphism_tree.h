//
// Created by jun on 2020/10/14.
//

#ifndef DACHENYUE_ISOMORPHISM_TREE_H
#define DACHENYUE_ISOMORPHISM_TREE_H

/*
   判断二叉树是否同构:
   给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则称两棵树是"同构"的。
   结构数组表示二叉树: 静态链表
 */

#include <iostream>
using namespace std;

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

int BuildTree(TreeNode T[]);

bool Isomorohic(Tree r1, Tree r2);

#endif //DACHENYUE_ISOMORPHISM_TREE_H
