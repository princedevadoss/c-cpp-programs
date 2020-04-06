#include <stdio.h>

struct bst {
    int data;
    struct bst *left;
    struct bst *right;
    struct bst *parent;
};

void deleteBST(struct bst *node) {
    struct bst *temp;
    if(node->left == NULL && node->right == NULL) {
        node = node -> parent;
        free(node -> left);
        free(node -> right);
        node -> left = NULL;
        node -> right = NULL;
    }
    else if(node -> left == NULL && node -> right != NULL) {
        node -> parent -> right = node -> right;
        node -> right -> parent = node -> parent;
    }
    else if(node -> left != NULL && node -> right == NULL) {
        node -> parent -> left = node -> left;
        node -> left -> parent = node -> parent;
    }
    else {
        struct bst *trav;
        if(node->parent->left == node) {
            node->parent->left = node -> right;
            node->right->parent = node -> parent;
            trav = node -> left;
            while(trav -> right != NULL) {
                trav = trav -> right;
            }
            trav -> right = node -> right -> left;
            node -> right -> left = node -> left;
            node -> left -> parent = node -> right;
            node -> right -> left -> parent = trav;
            free(node);
        }
        else {
            node -> parent -> right = node -> right;
            node -> right -> parent = node -> parent;
            trav = node -> left;
            while(trav -> right != NULL) {
                trav = trav -> right;
            }
            trav -> right = node -> right -> left;
            node -> right -> left -> parent = trav;
            node -> right -> left = node -> left;
            node -> left -> parent = node -> right;
            free(node);
        }
    }
}

int findSibling(struct bst *tree, int data1, int data2) {
    if(tree != NULL) {
        if(findSibling(tree->left, data1, data2) == 0) {
            if(tree->left != NULL && tree->right != NULL) {
                if((tree->left->data == data1 && tree->right->data == data2) || (tree->left->data == data2 && tree->right->data == data1)) {
                    return 1;
                }
            }
            return findSibling(tree -> right, data1, data2);
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int findComplete(struct bst *tree) {
    if(tree != NULL) {
        findComplete(tree->left);
        if(!((tree->left == NULL && tree -> right == NULL) || (tree->left != NULL && tree -> right != NULL))) {
            return 0;
        }
        return findComplete(tree->right);
    }
    else {
        return 1;
    }
}

void findBottomNodes(struct bst *tree) {
    if(tree != NULL){
        findBottomNodes(tree->left);
        if(tree->left == NULL && tree->right == NULL) {
            printf("%d\n", tree->data);
        }
        findBottomNodes(tree->right);
    }
}

void insertion(struct bst *t, int data, struct bst *root) {
    if(data <= t->data) {
        if(t->left != NULL) {
            insertion(t->left, data, root);
        }
        else {
            t -> left = malloc(sizeof(struct bst));
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
            t -> right = malloc(sizeof(struct bst));
            t -> right -> data = data;
            t -> right -> left = NULL;
            t -> right -> right = NULL;
            t -> right -> parent = t;
        }
    }
}

void printTree(struct bst *tr) {
    if(tr!=NULL) {
        printTree(tr -> left);
        printf("%d\n", tr -> data);
        printTree(tr -> right);
    }
}

void inOrder(struct bst *tr, int data) {
    if(tr!=NULL) {
        inOrder(tr -> left, data);
        if(tr->data == data) {
            deleteBST(tr);
        }
        inOrder(tr -> right, data);
    }
}

int main() {
    int comp, sib;
    struct bst *tree, *q;
    int arr[] = {2,8,1,6,9}, len = 5;
    tree = malloc(sizeof(struct bst));
    tree -> data = 5;
    tree -> left = NULL;
    tree -> right = NULL;
    tree -> parent = tree;

    q = tree;
    for(int i=0; i<len; i++) {
        insertion(q, arr[i], q);
    }

    printTree(q);
    printf("Complete tree?\n");
    comp = findComplete(q);
    printf("%d\n", comp);
    printf("Siblings?\n");
    sib = findSibling(q, 2, 3);
    printf("%d\n", sib);
    printf("Bottom nodes\n");
    findBottomNodes(q);
    // inOrder(q, 8);
    // printf("After deleting 8\n");
    // printTree(q);
    return 0;
}