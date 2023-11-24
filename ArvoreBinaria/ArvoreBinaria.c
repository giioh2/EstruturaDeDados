#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value);


struct TreeNode* insert(struct TreeNode* root, int value);


struct TreeNode* findMin(struct TreeNode* root);


struct TreeNode* deleteNode(struct TreeNode* root, int value);


int search(struct TreeNode* root, int value);


void inorderTraversal(struct TreeNode* root);


void freeTree(struct TreeNode* root);

int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    do {

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("///////////////////*///////////////////\n");
        printf("\n1. Inserir valores em diferentes posições.\n");
        printf("2. Remover valores da árvore.\n");
        printf("3. Realizar buscas por valores e verificar se estão presentes.\n");
        printf("4. Percorrer a árvore em diferentes ordens e exibir os valores.\n");
        printf("5. Sair\n");
        printf("///////////////////*///////////////////\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insira o valor a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Insira o valor a ser removido: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Insira o valor a ser buscado: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d está presente na árvore.\n", value);
                } else {
                    printf("%d não está presente na árvore.\n", value);
                }
                break;
            case 4:
                printf("Árvore em ordem (inorder): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }


        printf("\nPressione Enter para continuar...");
        getchar();  
        getchar();  

    } while (choice != 5);


    freeTree(root);

    return 0;
}



struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }

    return root;
}


struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        printf("Valor não encontrado na árvore.\n");
        return root;
    }

    if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else {
        // Nó com um ou nenhum filho
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }


        struct TreeNode* temp = findMin(root->right);


        root->key = temp->key;


        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}


int search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (value == root->key) {
        return 1; 
    } else if (value < root->key) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}


void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}


void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}