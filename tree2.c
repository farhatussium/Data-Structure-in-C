#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int val){
    if (root == NULL)
    {
        root = (struct Node*) malloc (sizeof(struct Node));
        root->data = val;
        root-> left = root->right = NULL;
        return root;
    }
    
    if (val < root ->data)
    {
        root-> left = insert(root->left, val);
    }else if(val > root->data){
        root->right = insert(root->right, val);
    }
    
    return root;
}

void inorder( struct Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    } 
}

void postoder(struct Node* root){
    if (root != NULL)
    {
        postoder(root->left);
        postoder(root->right);
        printf("%d ",root->data);
    }
    
}
int main(){

    int N, a;
    struct Node* root = NULL;

    printf("Enter the Number of Elements: ");
    scanf("%d", &N);

    printf("Enter the numbers: ");
    for (int i = 0; i < N; i++){
        scanf("%d", &a);
        root = insert(root, a);
    }
    
    printf("1. Display in Inorder \n");
    printf("2. Display in Pre-oder \n");
    printf("3. Display in Post-oder \n");

    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    printf("Display in Inorder \n");
        inorder(root);
        printf("\n");
        break;
    case 2:
    printf("Display in Pre-oder \n");
    preorder(root);
        printf("\n");
    break;
    case 3:
    printf("Display in Post-oder \n");
    postoder(root); 
        printf("\n");
    break;
    default:
        printf("Invalid Choice");
        break;
    }

    return 0;
}