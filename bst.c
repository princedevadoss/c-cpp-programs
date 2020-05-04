#include <stdio.h>
#include <math.h>

struct bst {
    int data;
    struct bst *left;
    struct bst *right;
    struct bst *parent;
};

struct treelink {
    struct bst *data;
    struct treelink *next;
};

struct treelink *link1, *qq;

int res = 0;

int checkLeaf(struct bst *node) {
    if(node -> left == NULL && node -> right == NULL) {
        return 1;
    }
    return 0;
}

void swapping(struct bst *child, struct bst *parent) {
    if(parent->left == child) {
        parent->left = child->right;
        if(parent->left!=NULL) {
        parent->left->parent = parent;
        }
        child-> right=parent;
        if(parent->parent == parent) {
	        child->parent = child;
        }
        else {
            child->parent = parent->parent;
        }
        if(parent->parent->left == parent) {
            child->parent->left=child;
        }
        else if(parent->parent->right==parent){
            child->parent->right = child;
        }
        parent->parent=child;
        // parent->left=NULL;
        // if(child->parent==child) {
        //     return child;
        // }
        // else {
        //     return NULL;
        // }
    }
    else
    {
        parent->right = child->left;
        if(parent->right!=NULL) {
        parent->right->parent = parent;
        }
        child-> left=parent;
        if(parent->parent == parent) {
	        child->parent = child;
        }
        else {
            child->parent = parent->parent;
        }
        
        if(parent->parent->left == parent) {
            child->parent->left=child;
        }
        else if(parent->parent->right==parent) {
            child->parent->right = child;
        }
        parent->parent=child;
        // parent->right=NULL;
        // if(child->parent==child) {
        //     return child;
        // }
        // else {
        //     return NULL;
        // }
    }  
}

struct bst* findChild(struct bst *node1, struct bst *node2) {
    if(node1 -> parent == node2) {
        return node1;
    }
    if(node2 -> parent == node1) {
        return node2;
    }
    return NULL;
}

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

int balanceFactor(struct bst *node) {
    return findMaxlevel(node->left,0) - findMaxlevel(node->right,0);
}

void treeBalanceFactor(struct bst *tree) {
    if(tree!=NULL) {
        treeBalanceFactor(tree->left);
        if(balanceFactor(tree) < -1 || balanceFactor(tree) > 1) {
            if(res==0) {
                link1 = malloc(sizeof(struct treelink));
                qq = link1;
                res=1;
            }
            link1->data = malloc(sizeof(struct bst));
            link1 -> data = tree;
            link1 -> next = malloc(sizeof(struct treelink));
            link1->next->data = NULL;
            link1 = link1 -> next;
        }
        treeBalanceFactor(tree->right);
    }
}

int commonParent(struct bst *tree, struct bst *node1, struct bst *node2) {
    if(node2 != tree) {
        struct bst *parent1, *parent2;
        parent1 = node1 -> parent;
        parent2 = node2 -> parent;
        while(parent1 != tree) {
            if(parent1 == parent2) {
                return parent1->data;
            }
            parent1 = parent1 -> parent;
        }
        return commonParent(tree, node1, node2->parent);
    }
    else {
        return tree->data;
    }
}

int sumOfNodes(struct bst *tree) {
    if(tree!=NULL) {
        return tree->data + sumOfNodes(tree->left) + sumOfNodes(tree->right);
    }
    else {
        return 0;
    }
}

int findNodeLevel1(struct bst *tree, int data, int count) {
    if(tree!=NULL) {
        int left = findNodeLevel1(tree->left, data, count + 1);
        int right = findNodeLevel1(tree->right, data, count + 1);
        if(tree->data == data) {
            return count + 1;
        }
        else {
            if(left != 0) {
                return left;
            }
            if(right != 0) {
                return right;
            }
            return 0;
        }
    }
    else {
        return 0;
    }
}

int findMaxlevel(struct bst *tree, int count) {
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

int findNodes(struct bst *tree, int count) {
    if(tree!=NULL) {
        return findNodes(tree->left, count + 1) + 1 + findNodes(tree->right, count + 1);
    }
    else {
        return 0;
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
        if(findComplete(tree->left) == 1) {
            if(!((tree->left == NULL && tree -> right == NULL) || (tree->left != NULL && tree -> right != NULL))) {
                return 0;
            }
            return findComplete(tree->right);
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
}

struct bst* findGivenNode(struct bst *tree, int data) {
    if(tree!=NULL) {
        struct bst* left = findGivenNode(tree->left, data);
        if(left!=NULL && left->data == data) {
            return left;
        }
        else {
            if(tree!=NULL && tree->data == data) {
                return tree;
            }
            return findGivenNode(tree->right, data);
        }
    }
    else {
        return NULL;
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
    int comp, sib, count, level=1, full = 0, lenn, maxlevel, desired,balancefactor;
    struct bst *tree, *q, *find, *find2, *pfind;
    int arr[] = {5,11,3,8,7,9,6}, len = 7;
    tree = malloc(sizeof(struct bst));
    tree -> data = 10;
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
    lenn = findNodes(q, 0);
    maxlevel = findMaxlevel(q, 0);
    printf("Maximum Level %d\n", maxlevel);
    printf("Total Number of Nodes %d\n", lenn);
    desired = pow(2, maxlevel) - 1;
    full = (desired == lenn) ? 1 : 0;
    printf("Full Binary Tree? %d\n", full);
    printf("Given Node Level? %d\n", findNodeLevel1(q, 5, 0));
    printf("Sum of tree? %d\n", sumOfNodes(q));
    int leftSum = sumOfNodes(q->left);
    int rightSum = sumOfNodes(q->right);
    if(leftSum > rightSum) {
        printf("left sum is greater %d\n", leftSum);
    }
    else {
        printf("right sum is greater %d\n", rightSum);
    }
    int leftcount = findNodes(q->left, 0);
    int rightcount = findNodes(q->right, 0);
    if(leftcount > rightcount) {
        printf("Left edges is %d\n", leftcount);
    }
    else {
        printf("Right edges is %d\n", rightcount);
    }
    // find = findGivenNode(q, 6);
    // find2 = findGivenNode(q, 12);
    // printf("Given Node %d\n", find->data);
    // printf("Common Parent %d\n", commonParent(q, find, find2));
    // balancefactor = balanceFactor(find);
    // printf("Balance factor: %d\n", balancefactor);
    // treeBalanceFactor(q);
    // while(qq->data != NULL) {
    //     printf("Unbalanced Node : %d\n",(qq->data->data));
    //     qq = qq -> next;
    // }
    pfind = findChild(findGivenNode(q,3), findGivenNode(q,5));
    if(pfind) {
        printf("checker...%d\n", checkLeaf(pfind));
        // if(checkLeaf(pfind)) {
            printf("%d %d\n", pfind->data, pfind->parent->data);
            swapping(pfind, pfind->parent);
            if(pfind->parent==q) {
                q =pfind->parent;
                printf("%d\n",q->left->data);
            }
            printf("%d %d\n", pfind->data, pfind->parent->data);
        // }
    }
    else {
        printf("They are not in parent child relationship");
    }
    
    printTree(q);
    // inOrder(q, 8);
    // printf("After deleting 8\n");
    // printTree(q);
    return 0;
}
