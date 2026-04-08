#include <stdio.h>
#include <stdlib.h>

// ─────────────────────────────────────────
//  NODE STRUCTURE
// ─────────────────────────────────────────
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ─────────────────────────────────────────
//  CREATE A NEW NODE
// ─────────────────────────────────────────
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

// ─────────────────────────────────────────
//  INSERT
// ─────────────────────────────────────────
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left  = insert(root->left,  value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("  [!] %d already exists. No duplicates allowed.\n", value);

    return root;
}

// ─────────────────────────────────────────
//  SEARCH
// ─────────────────────────────────────────
struct Node* search(struct Node* root, int value) {
    if (root == NULL) {
        printf("  [x] %d not found in tree.\n", value);
        return NULL;
    }
    if (value == root->data) {
        printf("  [✓] %d found!\n", value);
        return root;
    }
    if (value < root->data)
        return search(root->left,  value);
    else
        return search(root->right, value);
}

// ─────────────────────────────────────────
//  FIND MINIMUM VALUE (helper for delete)
// ─────────────────────────────────────────
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ─────────────────────────────────────────
//  FIND MAXIMUM VALUE
// ─────────────────────────────────────────
struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// ─────────────────────────────────────────
//  DELETE A NODE
// ─────────────────────────────────────────
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("  [x] %d not found. Nothing deleted.\n", value);
        return NULL;
    }

    if (value < root->data) {
        root->left  = deleteNode(root->left,  value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // CASE 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // CASE 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // CASE 3: Two children → replace with inorder successor
        else {
            struct Node* successor = findMin(root->right);
            root->data  = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

// ─────────────────────────────────────────
//  HEIGHT OF TREE
// ─────────────────────────────────────────
int height(struct Node* root) {
    if (root == NULL) return 0;
    int leftH  = height(root->left);
    int rightH = height(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

// ─────────────────────────────────────────
//  COUNT TOTAL NODES
// ─────────────────────────────────────────
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ─────────────────────────────────────────
//  TRAVERSALS
// ─────────────────────────────────────────

// Left → Root → Right  (gives SORTED output)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Root → Left → Right
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Left → Right → Root
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level-order (BFS) using a simple queue
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left  != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
}

// ─────────────────────────────────────────
//  PRINT TREE SIDEWAYS (visual)
// ─────────────────────────────────────────
void printTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n%*d\n", space, root->data);
    printTree(root->left, space);
}

// ─────────────────────────────────────────
//  FREE ALL MEMORY
// ─────────────────────────────────────────
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────
int main() {
    struct Node* root = NULL;

    // --- INSERT ---
    printf("==============================\n");
    printf("  INSERTING VALUES\n");
    printf("==============================\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 50);  // duplicate test
    printf("  Done! Tree built.\n\n");

    // --- VISUAL TREE ---
    printf("==============================\n");
    printf("  TREE STRUCTURE (sideways)\n");
    printf("==============================\n");
    printf("  (right side is at the top)\n");
    printTree(root, 0);
    printf("\n");

    // --- TRAVERSALS ---
    printf("==============================\n");
    printf("  TRAVERSALS\n");
    printf("==============================\n");
    printf("  Inorder   (sorted) : "); inorder(root);    printf("\n");
    printf("  Preorder           : "); preorder(root);   printf("\n");
    printf("  Postorder          : "); postorder(root);  printf("\n");
    printf("  Level Order (BFS)  : "); levelOrder(root); printf("\n\n");

    // --- SEARCH ---
    printf("==============================\n");
    printf("  SEARCH\n");
    printf("==============================\n");
    search(root, 40);
    search(root, 99);
    printf("\n");

    // --- MIN & MAX ---
    printf("==============================\n");
    printf("  MIN & MAX\n");
    printf("==============================\n");
    printf("  Minimum value : %d\n", findMin(root)->data);
    printf("  Maximum value : %d\n", findMax(root)->data);
    printf("\n");

    // --- HEIGHT & COUNT ---
    printf("==============================\n");
    printf("  HEIGHT & COUNT\n");
    printf("==============================\n");
    printf("  Tree height  : %d\n", height(root));
    printf("  Total nodes  : %d\n", countNodes(root));
    printf("\n");

    // --- DELETE ---
    printf("==============================\n");
    printf("  DELETE\n");
    printf("==============================\n");
    printf("  Deleting 20 (leaf)...\n");
    root = deleteNode(root, 20);
    printf("  Inorder: "); inorder(root); printf("\n\n");

    printf("  Deleting 30 (one child)...\n");
    root = deleteNode(root, 30);
    printf("  Inorder: "); inorder(root); printf("\n\n");

    printf("  Deleting 50 (two children)...\n");
    root = deleteNode(root, 50);
    printf("  Inorder: "); inorder(root); printf("\n\n");

    printf("  Deleting 99 (not in tree)...\n");
    root = deleteNode(root, 99);
    printf("\n");

    // --- FREE MEMORY ---
    freeTree(root);
    printf("==============================\n");
    printf("  Memory freed. Done!\n");
    printf("==============================\n");

    return 0;
}