#include "cerinte.h"
// creeaza un nod nou si il adauga la inceputul stivei pentru fiecare echipa
void push(stiva **top, Team team)
{
    stiva *newNode = (stiva *)malloc(sizeof(stiva));
    newNode->team = team;
    newNode->next = *top;
    *top = newNode;
}
// verifica daca stiva este goala si elimina nodul din varf
void pop(stiva **top)
{
    if (*top == NULL)
        return;
    stiva *temp = (*top);
    *top = (*top)->next;
    free(temp);
}
// sterge intreaga stiva
void deleteStack(stiva **top)
{
    stiva *temp;
    while ((*top) != NULL)
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
// parcurge stiva de la inceput si afiseaza numele si punctajul fiecarei echipe
void display_winners(FILE *r, stiva *top, int round)
{

    fprintf(r, "WINNERS OF ROUND NO:%d:\n", round);
    while (top != NULL)
    {
        fprintf(r, "%s", top->team.name, top->team.teamPoints);
        display_inline(top->team.name, r);
        fprintf(r, " - %.2f\n", top->team.teamPoints);

        top = top->next;
    }
    fprintf(r, "\n");
}
// este luata din curs si creeaza o coada goala cu inceputul si sfarsitul NULL
coada *createQueue()
{
    coada *q;
    q = (coada *)malloc(sizeof(coada));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}
// creeaza un nod pentru fiecare echipa si o  adauga la sfarsitul cozii q
void enQueue(coada *q, Team team)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->team = team;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->rear = newNode;

    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }

    if (q->front == NULL)
        q->front = q->rear;
}
// verifica daca coada nu este goala si sterge echipa din fata cozii q
void deQueue(coada *q)
{
    Node *aux;
    if (q->front == NULL)
        return;
    aux = q->front;
    q->front = (q->front)->next;
    free(aux);
}
// adauga echipele intr-un meci. Parcurge lista de echipe si le adauga in coada q. Compara punctajele echipelor si le adauga in stivele WIN si LOSE (castigatori si pierzatori)
void add_Team_match(Node *head, stiva **WIN, stiva **LOSE, coada *q)
{
    Team aux_echipa;
    while (head != NULL)
    {
        aux_echipa = head->team;
        enQueue(q, head->team);
        head = head->next;
        enQueue(q, head->team);
        if (aux_echipa.teamPoints <= head->team.teamPoints)
        {
            head->team.teamPoints += 1;
            push(&*WIN, head->team);
            push(&*LOSE, aux_echipa);
        }
        else
        {
            aux_echipa.teamPoints += 1;
            push(&*LOSE, head->team);
            push(&*WIN, aux_echipa);
        }
        head = head->next;
    }
}
// adauga spatii pana la o lungime fixata. Calculeaza spatiile necesare si le afiseaza
void display_inline(char *nume, FILE *r)
{
    int space = strlen(nume);
    while (space < 33)
    {
        fprintf(r, " ");
        space++;
    }
}
// afiseaza continutul cozii si meciurile jucate intr-o runda. Parcurge coada si afiseaza numerele echipelor in ordinea in care au fost adaugate in coada
void display_queue(coada *Q, FILE *r, int nr)
{
    fprintf(r, "--- ROUND NO:%d:\n", nr);
    while (Q->front != NULL)
    {
        fprintf(r, "%s", Q->front->team.name);
        display_inline(Q->front->team.name, r);
        fprintf(r, "-");
        deQueue(Q);
        display_inline(Q->front->team.name, r);
        fprintf(r, "%s\n", Q->front->team.name);
        deQueue(Q);
    }
    fprintf(r, " \n");
}
// adauga echipele intr-un meci. Parcurge stiva WIN si adauga perechi in coada q. Compara punctajele echipelor si le adauga in stivele WIN si LOSE in functie de rezultate
void add_Team_match_stiva(stiva **WIN, stiva **LOSE, coada *q)
{

    Team aux_echipa;
    stiva *aux_stiva = NULL;
    while (*WIN != NULL)
    {
        aux_echipa = (*WIN)->team;
        enQueue(q, aux_echipa);
        (*WIN) = (*WIN)->next;
        enQueue(q, (*WIN)->team);
        if (aux_echipa.teamPoints <= (*WIN)->team.teamPoints)
        {
            (*WIN)->team.teamPoints += 1;
            push(&aux_stiva, (*WIN)->team);
            push(&*LOSE, aux_echipa);
        }
        else
        {
            aux_echipa.teamPoints += 1;
            push(&*LOSE, (*WIN)->team);
            push(&aux_stiva, aux_echipa);
        }
        *WIN = (*WIN)->next;
    }
    *WIN = aux_stiva;
}

void adauga_din_stiva_inlista(Node **head, stiva *top)
{
    while (top != NULL)
    {
        AddAtEnd(&*head, top->team);
        top = top->next;
    }
}
void freeStack(stiva *top) {
    stiva *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void freeQueue(coada *q) {
    Node *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

// implementeaza algoritmul pentru desfasurarea meciurilor in etape. Creeaza o coada Q si stivele WIN LOSE. Actualizeaza echipele in coada si stive, afiseaza meciurile echipelor castigatoare, returneaza ultimele 8 echipe
Node *cerinta3(Node *head, FILE *r, int nr_echipe) {
    coada *Q = createQueue();
    stiva *WIN = NULL, *LOSE = NULL;
    Node *last = NULL;
    int nr = 1;
    add_Team_match(head, &WIN, &LOSE, Q);
    display_queue(Q, r, nr);
    display_winners(r, WIN, nr);
    nr_echipe = nr_echipe / 2;
    deleteStack(&LOSE);
    nr++;

    while (nr_echipe > 1) {
        add_Team_match_stiva(&WIN, &LOSE, Q);
        display_queue(Q, r, nr);
        display_winners(r, WIN, nr);
        nr_echipe = nr_echipe / 2;
        deleteStack(&LOSE);
        nr++;

        if (nr_echipe == 8) {
            adauga_din_stiva_inlista(&last, WIN);
        }
    }

    freeStack(WIN);
    freeStack(LOSE);
    freeQueue(Q);

    return last;
}
