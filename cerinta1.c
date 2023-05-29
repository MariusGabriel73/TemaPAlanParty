#include "cerinte.h"
// scrie in fisierul r.out numele echipei
void display(Node *head, FILE *r)
{
    while (head != NULL)
    {
        fprintf(r, "%s\n", head->team.name);
        head = head->next;
    }
    fprintf(r, "\n");
}
// citeste din fisierul d.in datele si le introduce in lista ma folosesc de 2 vectori                                          pentru a introduce numele si prenumele jucatorilor si inca unul pentru numele echipei
Team Read_The_Team(FILE *d)
{
    Team team;
    fscanf(d, "%d", &team.nr_players);
    team.players = (Player *)malloc(team.nr_players * sizeof(Player));
    team.teamPoints = 0;
    char *nume_echipa = calloc(100, sizeof(char));
    char nume[50];
    char prenume[50];
    fgets(nume_echipa, 100, d);
    team.name = (char *)calloc(strlen(nume_echipa) + 1, sizeof(char));
    strcpy(nume_echipa + strlen(nume_echipa) - 1, "\0");
    strcpy(team.name, nume_echipa + 1);

    for (int i = 0; i < team.nr_players; i++)
    {
        fscanf(d, "%s %s %d", nume, prenume, &team.players[i].points);
        team.players[i].firstName = (char *)calloc(strlen(nume) + 1, sizeof(char));
        team.players[i].secondName = (char *)calloc(strlen(prenume) + 1, sizeof(char));
        strcpy(team.players[i].firstName, nume);
        strcpy(team.players[i].secondName, prenume);
        team.teamPoints = team.teamPoints + team.players[i].points;
    }
    team.teamPoints = (float)team.teamPoints / team.nr_players;
    return team;
}
// uata din curs si adauga la inceput date
void AddAtBeginning(Node **head, Team team)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->team = team;
    newNode->next = *head;
    *head = newNode;
}
// luata din curs si adauga la inceput date
void AddAtEnd(Node **head, Team team)
{
    Node *aux = *head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->team = team;

    if (*head == NULL)
    {
        AddAtBeginning(head, team);
    }
    else
    {
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = newNode;
        newNode->next = NULL;
    }
}
