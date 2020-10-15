//
// Created by jun on 2020/10/13.
//

#include "tree.h"
#include <stack>
#include <queue>

/**
 * 先序递归
 * @param BT
 */
void PreOrderTraversal(BinTree BT) {
    if (BT) {
        printf("%d ", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

/**
 * 中序递归
 * @param BT
 */
void InOrderTraversal(BinTree BT) {
    if (BT) {
        InOrderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InOrderTraversal(BT->Right);
    }
}

/**
 * 后序递归
 * @param BT
 */
void PostOrderTraversal(BinTree BT) {
    if (BT) {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}

/**
 * 先序非递归
 * @param BT
 */
void PreOrderNonRecursive(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> S;
    while (T || !S.empty()) {
        while (T) {
            printf("%5d", T->Data);
            S.push(T);      // 第1次遇到T
            T = T->Left;
        }
        if (!S.empty()) {
            T = S.top();
            S.pop();
            T = T->Right;
        }
    }
}

/**
 * 中序非递归
 * @param BT
 */
void InOrderTraversalNonRecursive(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> S;
    while (T || !S.empty()) {
        while (T) {
            S.push(T);
            T = T->Left;
        }
        if (!S.empty()) {
            T = S.top();
            S.pop();
            printf("%5d ", T->Data);    // 第2次遇到T
            T = T->Right;
        }
    }
}

/**
 * 后序非递归
 * @param BT
 */
void PostOrderTraversalNonRecursive(BinTree BT) {
    BinTree T = BT, Pre = nullptr;
    stack<BinTree> S;
    while (T || !S.empty()) {
        while (T) {
            S.push(T);
            T = T->Left;
        }
        if (!S.empty()) {
            T = S.top();
            if (T->Right && T->Right != Pre)
                T = T->Right;
            else {
                printf("%5d", T->Data);     // 第3次遇到T
                Pre = T;
                T = nullptr;
                S.pop();
            }
        }
    }
}

/**
 * 层次遍历
 * @param BT
 */
void LevelOrderTraversal(BinTree BT) {
    queue<BinTree> Q;
    BinTree T = BT;
    if (!BT) return;
    Q.push(BT);
    while (!Q.empty()) {
        T = Q.front();
        Q.pop();
        printf("%d\n", T->Data);
        if (T->Left) Q.push(T->Left);
        if (T->Right) Q.push(T->Right);
    }
}

/**
 * 打印叶子结点
 * @param BT
 */
void PreOrderPrintLeaves(BinTree BT) {
    if (BT) {
        if (!BT->Left && !BT->Right)
            printf("%d", BT->Data);
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

/**
 * 求二叉树的高度
 * @param BT
 * @return
 */
int PostOrderGetHeight(BinTree BT) {
    int HL, HR;
    if(BT) {
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        return max(HL, HR)  + 1;
    }
    return 0;
}

/**
 * 二叉搜索树的查找操作Find
 * @param x
 * @param BST
 * @return
 */
BinTree Find(ElementType X, BinTree BST) {
    if (!BST) return nullptr; /* 空树，查找失败 */
    if (X > BST->Data)
        return Find(X, BST->Right);    /* 在右子树中继续查找 */
    else if (X < BST->Data)
        return Find(X, BST->Left);    /* 在左子树中继续查找 */
    else
        return BST;
}

/**
 * 由于非递归函数的执行效率更高，可将尾递归函数改为迭代函数
 * @param x
 * @param BST
 * @return
 */
BinTree IterFind(ElementType X, BinTree BST) {
    while (BST) {
        if (X > BST->Data)
            BST = BST->Right;
        else if (X < BST->Data)
            BST = BST->Left;
        else
            return BST;
    }
    return nullptr;
}

/**
 * 查找最小元素的递归函数
 * @param BST
 * @return
 */
BinTree FindMin(BinTree BST) {
    if (!BST) return nullptr;
    else if (!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}

/**
 * 查找最大元素的迭代函数
 * @param BST
 * @return
 */
BinTree FindMax(BinTree BST) {
    if (BST)
        while (BST->Right) BST = BST->Right;
    return BST;
}

/**
 * 二叉搜索树的插入
 * @param x
 * @param BST
 * @return
 */
BinTree Insert(ElementType X, BinTree BST) {
    if (!BST) {
        BST = (BinTree) malloc(sizeof(TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = nullptr;
    } else {
        if (X < BST->Data)
            BST->Left = Insert(X, BST->Left);
        else if (X > BST->Data)
            BST->Right = Insert(X, BST->Right);
    }
    return BST;
}

/**
 * 二叉搜索树的删除
 * @param x
 * @param BST
 * @return
 */
BinTree Delete(ElementType X, BinTree BST) {
    BinTree tmp;
    if (!BST) printf("要删除的元素未找到\n");
    else if (X < BST->Data)
        BST->Left = Delete(X, BST->Left);
    else if (X > BST->Data)
        BST->Right = Delete(X, BST->Right);
    else {
        if (BST->Left && BST->Right) {
            tmp = FindMin(BST->Right);
            BST->Data = tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right);
        } else {
            tmp = BST;
            if (!BST->Left)
                BST = BST->Right;
            else if (!BST->Right)
                BST = BST->Left;
            free(tmp);
        }
    }
    return BST;
}


