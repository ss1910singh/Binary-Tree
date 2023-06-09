#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create(int data) {
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct tree* insert(struct tree* root, int data) {
    if (root == NULL) {
        return create(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void in(struct tree* root) {
    if (root == NULL) {
        return;
    }
    in(root->left);
    printf("%d ", root->data);
    in(root->right);
}

void pre(struct tree* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    pre(root->left);
    pre(root->right);
}

void post(struct tree* root) {
    if (root == NULL) {
        return;
    }
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}

struct tree* delete(struct tree* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct tree* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct tree* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct tree* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct tree* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder traversal: ");
                in(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder traversal: ");
                pre(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal: ");
                post(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the element to delete: ");
                scanf("%d",&data);
                break;
            case 6:
            exit(0);

            default:
            printf("\nInvalid choice!!");
            }
            }
            return 0;
            }