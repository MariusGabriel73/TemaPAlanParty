#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct
{
    char *firstName;
    char *secondName;
    int points;
} Player;

typedef struct
{
    Player *players;
    char *name;
    float teamPoints;
    int nr_players;
} Team;

typedef struct node
{
    Team team;
    struct node *next;
} Node;

typedef struct coada
{
    Node *front, *rear;
} coada;

typedef struct stiva
{
    Team team;
    struct stiva *next;
} stiva;

typedef struct tree
{
    Team team;
    struct tree *left;
    struct tree *right;
    int height;
} Tree;

// cerinta1
void display(Node *head, FILE *g);
Team Read_The_Team(FILE *f);
void AddAtBeginning(Node **head, Team team);
void AddAtEnd(Node **head, Team team);
// cerinta2
int PowerOfTwo(int n);
float MinScore(Node *head);
void deleteTeam(Node **head, float minScore);
void eliminateTeams(Node **head, int *nr_teams);
// cerinta3
void push(stiva **top, Team team);
void pop(stiva **top);
void deleteStack(stiva **top);
void display_winners(FILE *r, stiva *top, int round);
coada *createQueue();
void enQueue(coada *q, Team v);
void deQueue(coada *q);
void add_Team_match(Node *head, stiva **WIN, stiva **LOSE, coada *q);
void display_inline(char *nume, FILE *r);
void display_queue(coada *Q, FILE *r, int nr);
void add_Team_match_stiva(stiva **WIN, stiva **LOSE, coada *q);
void adauga_din_stiva_inlista(Node **head, stiva *top);
void freeQueue(coada *q);
Node *cerinta3(Node *head, FILE *r, int nr_echipe);
// cerinta4
void Display_Descending(Tree *root, FILE *r);
Tree *insertNode(Tree *root, Team team);
void FreeTree(Tree *root);
Tree *cerinta4(FILE *r, Node *last);
// cerinta5
void cerinta5(FILE *r, Node *last);