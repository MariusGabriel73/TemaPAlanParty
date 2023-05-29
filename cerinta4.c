#include "cerinte.h"

Tree* insertNode(Tree* root, Team team) {
    if (root == NULL) {
        Tree* newNode = (Tree*)malloc(sizeof(Tree));
        newNode->team = team;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (team.teamPoints > root->team.teamPoints || (team.teamPoints == root->team.teamPoints && strcmp(team.name, root->team.name) > 0))
        root->left = insertNode(root->left, team);
    else
        root->right = insertNode(root->right, team);

    return root;
}
void Display_Descending(Tree *root, FILE *r) {
    if (root != NULL) {
        Display_Descending(root->left,r);
        fprintf(r,"%s ", root->team.name);
        display_inline(root->team.name,r);
        fprintf(r,"- %.2f\n", root->team.teamPoints);       
        Display_Descending(root->right,r);
    }
}
void FreeTree(Tree* root) {
    if (root == NULL) {
        return;
    }

    FreeTree(root->left);
    FreeTree(root->right);

    free(root);
}

Tree *cerinta4(FILE *r, Node *last) {
Tree *root = NULL;
Tree *tree = NULL;
Node *current = last;
while (current != NULL) {
    root = insertNode(root, current->team);
    current = current->next;
}
fprintf(r,"TOP 8 TEAMS:\n");
Display_Descending(root,r);
FreeTree(root);
return tree;
}