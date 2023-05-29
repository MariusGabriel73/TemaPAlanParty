#include "cerinte.h"

void display(Node *head,FILE *g)
{   
    //fprintf(g,"Teams: \n");
    while(head != NULL)
    {   
        fprintf(g ,"%s\n", head->team.name);
        //printf("%s\n",head->team.name);
        head = head->next;
    }
    fprintf(g,"\n");
}
//functia citeste fiecare echipa din fisierul d.in si o adauga in lista 
Team Read_The_Team(FILE *f)
{
    Team team;
    fscanf(f, "%d", &team.nr_players);
    team.players = (Player *)malloc(team.nr_players * sizeof(Player));
    team.teamPoints = 0;
    // Folosim 2 vectori pentru a putea introduce în listă numele și prenumele jucătorilor
    // și încă unul pentru numele echipei
    char *nume_echipa = calloc(100, sizeof(char));
    char nume[50];
    char prenume[50];
    fgets(nume_echipa, 100, f);
    team.name = (char *)calloc(strlen(nume_echipa) + 1, sizeof(char));
    strcpy(nume_echipa + strlen(nume_echipa) - 1, "\0");
    strcpy(team.name, nume_echipa + 1);

    // Verificăm dacă există un spațiu la sfârșitul numelui echipei și îl eliminăm
    int len = strlen(team.name);
    if (len > 0 && team.name[len - 1] == ' ')
    {
        team.name[len - 1] = '\0';
    }

    for (int i = 0; i < team.nr_players; i++)
    {
        fscanf(f, "%s %s %d", nume, prenume, &team.players[i].points);
        team.players[i].firstName = (char *)calloc(strlen(nume) + 1, sizeof(char));
        team.players[i].secondName = (char *)calloc(strlen(prenume) + 1, sizeof(char));
        strcpy(team.players[i].firstName, nume);
        strcpy(team.players[i].secondName, prenume);
        team.teamPoints = team.teamPoints + team.players[i].points;
    }
    team.teamPoints = (float)team.teamPoints / team.nr_players;
    return team;
}


//functia adauga la inceput echipele 
void AddAtBeginning(Node **head,Team team)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->team = team;
    newNode->next = *head;
    *head = newNode;
}
void AddAtEnd(Node** head, Team team) {
    Node* aux = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->team = team;
    
    if (*head == NULL) {
        AddAtBeginning(head, team);
    } else {
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = newNode;
        newNode->next = NULL;
    }
}
