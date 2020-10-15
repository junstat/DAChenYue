//
// Created by jun on 2020/10/14.
//

#include "isomorphism_tree.h"


int main() {
    // 建二叉树1
    // 建二叉树2
    Tree R1, R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);

    if (Isomorohic(R1, R2)) printf("Yes\n");
    else printf("No\n");

    // 判别是否同构并输出
    return 0;
}

bool Isomorohic(Tree R1, Tree R2) {
    if ((R1 == Null) && (R2 == Null))   /* both empty */
        return true;
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
        return false;   /* one of them is empty */
    if (T1[R1].Element != T2[R2].Element)
        return false;   /* roots are different */
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return Isomorohic(T1[R1].Right, T2[R2].Right);  /* both have no left subtree */
    if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
        ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
        /* no need to swap the left and the right */
        return (Isomorohic(T1[R1].Left, T2[R2].Left) &&
                Isomorohic(T1[R1].Right, T2[R2].Right));
    else
        /* need to swap the left and the right */
        return (Isomorohic(T1[R1].Left, T2[R2].Right) &&
                Isomorohic(T1[R1].Right, T2[R2].Left));
}

Tree BuildTree(TreeNode T[]) {
    Tree Root;
    int N, i;
    char cl, cr;
    scanf("%d", &N);
    int check[N];
    if (N) {
        for (i = 0; i < N; i++) check[i] = 0;
        for (i = 0; i < N; i++) {
            scanf("%c %c %c", &T[i].Element, &cl, &cr);
            if (cl != '-') {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            } else T[i].Left = Null;
            if (cr != '-') {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            } else T[i].Right = Null;
        }
        for (i = 0; i < N; i++)
            if (!check[i]) break;
        Root = i;
    }
    return Root;
}
