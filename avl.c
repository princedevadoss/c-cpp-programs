#include<stdio.h>
#include<stdlib.h>

struct avl {
    int data;
    struct avl *left;
    struct avl *right;
    struct avl *parent;
};

int findMaxlevel(struct avl *tree, int count) {
    if(tree!=NULL) {
        int left = findMaxlevel(tree->left, count + 1);
        int right = findMaxlevel(tree->right, count + 1);
        if(left > right) {
            return left;
        }
        else {
            return right;
        }
    }
    else {
        return count;
    }
}

int balanceFactor(struct avl *node) {
    return findMaxlevel(node->left,0) - findMaxlevel(node->right,0);
}

int treeBalanceFactor(struct avl *tree) {
    if(tree!=NULL) {
        int left = treeBalanceFactor(tree->left);
        if(left == 0) {
            return 0;
        }
        if(balanceFactor(tree) < -1 || balanceFactor(tree) > 1) {
            return 0;
        }
        return treeBalanceFactor(tree->right);
    }
    else {
        return 1;
    }
}

void insertion(struct avl *t, int data, struct avl *root) {
    if(data <= t->data) {
        if(t->left != NULL) {
            insertion(t->left, data, root);
        }
        else {
            t -> left = malloc(sizeof(struct avl));
            t -> left -> data = data;
            t -> left -> left = NULL;
            t -> left -> right = NULL;
            t -> left -> parent = t;
        }
    }
    else {
        if(t->right != NULL) {
            insertion(t->right, data, root);
        }
        else {
            t -> right = malloc(sizeof(struct avl));
            t -> right -> data = data;
            t -> right -> left = NULL;
            t -> right -> right = NULL;
            t -> right -> parent = t;
        }
    }
}

void printTree(struct avl *tr) {
    if(tr!=NULL) {
        printTree(tr -> left);
        printf("%d\n", tr -> data);
        printTree(tr -> right);
    }
}

int main() {
    struct avl *tree, *q;
    int arr[] = {5,11,3,8}, len = 4;
    tree = malloc(sizeof(struct avl));
    tree->data = 10;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = tree;
    q = tree;
    for(int i=0; i<len; i++) {
        insertion(q, arr[i], q);
    }
    printTree(q);
    printf("%d",treeBalanceFactor(q));
}