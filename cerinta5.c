#include "cerinte.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(Tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Tree *rightRotate(Tree *y)
{
    Tree *x = y->left;
    Tree *T2 = x->right;

    // Realizează rotația
    x->right = y;
    y->left = T2;

    // Actualizează înălțimile
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Tree *leftRotate(Tree *x)
{
    Tree *y = x->right;
    Tree *T2 = y->left;

    // Realizează rotația
    y->left = x;
    x->right = T2;

    // Actualizează înălțimile
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Tree *createNode(Team team)
{
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    newNode->team = team;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Tree *insertNodeAVL(Tree *root, Team team)
{
    if (root == NULL)
    {
        return createNode(team);
    }

    if (team.teamPoints < root->team.teamPoints)
    {
        root->left = insertNodeAVL(root->left, team);
    }
    else if (team.teamPoints > root->team.teamPoints)
    {
        root->right = insertNodeAVL(root->right, team);
    } else {
                if (strcmp(team.name, root->team.name) < 0) {
            root->left = insertNodeAVL(root->left, team);
        } else if (strcmp(team.name, root->team.name) > 0) {
            root->right = insertNodeAVL(root->right, team);
        } else {
        return root;
    }
    }

    // Actualizează înălțimea
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Echilibrează arborele
    int balanceFactor = getBalanceFactor(root);

    // Cazul stânga-stânga
    if (balanceFactor > 1 && team.teamPoints < root->left->team.teamPoints)
    {
        return rightRotate(root);
    }

    // Cazul dreapta-dreapta
    if (balanceFactor < -1 && team.teamPoints > root->right->team.teamPoints)
    {
        return leftRotate(root);
    }

    // Cazul stânga-dreapta
    if (balanceFactor > 1 && team.teamPoints > root->left->team.teamPoints)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Cazul dreapta-stânga
    if (balanceFactor < -1 && team.teamPoints < root->right->team.teamPoints)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%s - %.2f\n", root->team.name, root->team.teamPoints);
    inorderTraversal(root->right);
}
void displayLevel(Tree *root, FILE *r)
{
    if (root == NULL)
    {
        return;
    }
    fprintf(r,"\nTHE LEVEL 2 TEAMS ARE:\n");
    if (root->left != NULL)
    {
        if (root->left->left != NULL)
        {
            fprintf(r,"%s\n", root->left->left->team.name);
        }
        if (root->left->right != NULL)
        {
            fprintf(r,"%s\n", root->left->right->team.name);
        }
    }

    if (root->right != NULL)
    {
        if (root->right->left != NULL)
        {
            fprintf(r,"%s\n", root->right->left->team.name);
        }
        if (root->right->right != NULL)
        {
            fprintf(r,"%s\n", root->right->right->team.name);
        }
    }
}

void cerinta5(FILE *r, Node *last)
{
    Tree *root = NULL;
    Node *current = last;
    while (current != NULL)
    {
        root = insertNodeAVL(root, current->team);
        current = current->next;
    }
    displayLevel(root, r);
}


