#include "cerinte.h"
// testeaza recursive daca un numar este putere a lui 2
int PowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}
// MinScore cauta in lista scorul minim
float MinScore(Node *head)
{
    float minScore = 99999.0;

    while (head != NULL)
    {
        if (head->team.teamPoints < minScore)
        {
            minScore = head->team.teamPoints;
        }
        head = head->next;
    }

    return minScore;
}
// cauta prima echipa cu scorul minim cu ajutorul functie de mai sus si o elimina daca nu se gaseste iese din functie daca este capul listei atunci actualizam head cu urmatoarea valoare, iar la sfarsit elibarem memoria
void deleteTeam(Node **head, float minScore)
{
    Node *aux = *head;
    Node *anterior = NULL;

    // Cauta prima echipa cu scorul minim
    while (aux != NULL && aux->team.teamPoints != minScore)
    {
        anterior = aux;
        aux = aux->next;
    }

    // Daca nu se gaseste echipa
    if (aux == NULL)
        return;

    // Daca echipa este capul listei
    if (anterior == NULL)
    {
        *head = aux->next;
    }
    else
    {
        anterior->next = aux->next;
    }

    free(aux);
}

// se foloseste de subprogramele de mai sus pentru a sterge echipele cu scorul minim pana numarul lor este mai mic sau egal cu o putere a lui 2
void eliminateTeams(Node **head, int *nr_teams)
{

    while (PowerOfTwo(*nr_teams) != 1)
    {
        float minScore = MinScore(*head);
        deleteTeam(&*head, minScore);
        *nr_teams = *nr_teams - 1;
    }
}