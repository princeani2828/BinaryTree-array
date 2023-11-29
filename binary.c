#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct TreeNode {
    int data;
};

void initialize(struct TreeNode tree[], int size) {
    for (int i = 0; i < size; i++) {
        tree[i].data = -1;
    }
}

void insert(struct TreeNode tree[], int size, int value) {
    for (int i = 0; i <size; i++) {
        if (tree[i].data == -1) {
            tree[i].data = value;
            return;
        }
    }
    printf("The Tree is Full\n");
}

bool search(struct TreeNode tree[], int size, int value) {
    for (int i = 0; i <size; i++) {
        if (tree[i].data == value) {
            return true;
        }
    }
    return false;
}

void display(struct TreeNode tree[], int size) {
    printf("Binary Tree: ");
    for (int i = 0; i < size; i++) {
        if (tree[i].data != -1) {
            printf("%d ", tree[i].data);
        }
    }
    printf("\n");
}



int main() {
    int n, inputValue;

    printf("Enter the value of Tree Size: ");
    scanf("%d", &n);

    struct TreeNode binaryTree[MAX_SIZE];

    initialize(binaryTree, n);

    printf("Enter values for the binary tree (enter -1 to stop):\n");

    do {
        printf("Enter a value: ");
        scanf("%d", &inputValue);

        if (inputValue != -1) {
            insert(binaryTree, n, inputValue);
        }

    } while (inputValue != -1);

    int k;
    printf("Enter the value of choice(To Search .1,Display .2): ");
    scanf("%d", &k);

    switch (k) {
    case 1:
        printf("Enter a value to search: ");
        scanf("%d", &inputValue);
        if (search(binaryTree, n, inputValue)) {
            printf("Value %d found in the tree.\n", inputValue);
        } else {
            printf("Value %d not found in the tree.\n", inputValue);
        }
        break;

    case 2:
        display(binaryTree, n);
        break;
        

    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}