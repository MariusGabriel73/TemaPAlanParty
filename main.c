#include "cerinte.h"

int main()
{

    FILE *d = fopen("d.in", "r");
    if (d == NULL)
    {
        printf("Nu s-a realizat citirea din fisierul d.in\n");
        return 1;
    }
    FILE *c = fopen("c.in", "r");
    if (c == NULL)
    {
        printf("Nu s-a realizat citirea din fisierul c.in\n");
        return 1;
    }
    FILE *r = fopen("r.out", "w");
    if (r == NULL)
    {
        printf("Fisierul .out nu a putut fi realizat");
        return 1;
    }

    int cod[5];
    for (int i = 0; i < 5; i++)
        fscanf(c, "%d", &cod[i]);

    Node *head = NULL, *last;
    int nr_teams;
    fscanf(d, "%d", &nr_teams);
    //cerinta1
    if (cod[0] == 1)
        for (int i = 0; i < nr_teams; i++)
            AddAtBeginning(&head, Read_The_Team(d));
    //cerinta2
    if (cod[1] == 1)
        eliminateTeams(&head, &nr_teams);

    if (cod[0] || cod[1])
        display(head, r);
    //cerinta3
    if (cod[2] == 1)
        last = cerinta3(head, r, nr_teams);
    //cerinta4
    if(cod[3] == 1){
        Tree* tree = NULL;
        tree = cerinta4(r, last);
        Display_Descending(tree,r);
        FreeTree(tree);
    }
    //cerinta5
    if (cod[4] == 1)
    {
        cerinta5(r, last);
    }
    fclose(d);
    fclose(c);
    fclose(r);
    return 0;
}