# TemaPAlanParty
Nume: Banu Marius-Gabriel
Grupa: 314AA
LAN Party Tema numarul 1
Descriere:
Programul primește informații despre echipe dintr-un fișier și elimină echipele cu cel mai mic punctaj până când numărul total al acestora devine mai mic sau egal cu o putere a lui doi. Inițial, calculează cel mai mare număr de echipe care poate fi reținut într-o putere a lui doi, având în vedere numărul total de echipe. Apoi,l organizează meciuri între echipe și afișează câștigătorii fiecărui meci. La final, programul realizează un clasament al celor mai bune 8 echipe, pe baza punctajelor obținute. De asemenea, afișează echipele de pe nivelul doi din arborele AVL ( momentan afișează doar 3 echipe și nu înțeleg de ce). A fost un lucru bun că am primit o astfel de temă chiar dacă mi-a  dat mari bătăi de cap și sunt 100% sigur că se pot găsi soluții mult mai eficiente pentru rezolvarea ei, momentan sunt fericit că merge(sper).

Explicații funcții:

1-cerinte.h: este header-ul în care sunt definite toate funcțiile folosite, împreună cu structurile pentru stivă, coadă, listă și arbore.
2-cerinta1.c:

Funcția display afișează numele echipei în fișierul r.out.
Funcția Read_The_Team citește informațiile despre echipe din fișierul d.in și le introduce în listă. Se folosesc doi vectori pentru a memora numele și prenumele jucătorilor, precum și unul pentru numele echipei.
Funcția AddAtBeginning adaugă un nod la începutul listei.
Funcția AddAtEnd adaugă un nod la sfârșitul listei.
3-cerinta2.c:
Funcția PowerOfTwo verifică recursiv dacă un număr este o putere a lui 2.
Funcția MinScore caută scorul minim în listă.
Funcția deleteTeam caută prima echipă cu scorul minim folosind funcția de mai sus și o elimină. Dacă nu se găsește, iese din funcție. Dacă este capul listei, actualizează head cu următoarea valoare, iar la sfârșit eliberează memoria.
Funcția eliminateTeams folosește subprogramele de mai sus pentru a elimina echipele cu scorul minim până când numărul lor este mai mic sau egal cu o putere a lui 2.
4-cerinta3.c:
Funcția push creează un nod nou și îl adaugă la începutul stivei pentru fiecare echipă.
Funcția pop verifică dacă stiva este goală și elimină nodul din vârf.
Funcția deleteStack șterge întreaga stivă.
Funcția display_winners parcurge stiva de la început și afișează numele și punctajul fiecărei echipe.
Funcția createQueue creează o coadă goală cu începutul și sfârșitul NULL.
Funcția enQueue creează un nod pentru fiecare echipă și îl adaugă la sfârșitul cozii q.
Funcția deQueue verifică dacă coada nu este goală și elimină echipa din fața cozii q.
Funcția add_Team_match adaugă echipele într-un meci. Parcurge lista de echipe și le adaugă în coadă q. Compară punctajele echipelor și le adaugă în stivele WIN și LOSE (câștigători și pierzători).
Funcția display_inline adaugă spații până la o lungime fixată. Calculează spațiile necesare și le afișează.
Funcția display_queue afișează conținutul cozii și meciurile jucate într-o rundă. Parcurge coada și afișează numerele echipelor în ordinea în care au fost adăugate în coadă.
Funcția add_Team_match_stiva adaugă echipele într-un meci. Parcurge stiva WIN și adaugă perechi în coada q. Compară punctajele echipelor și le adaugă în stivele WIN și LOSE în funcție de rezultate.
Funcția cerinta3 implementează algoritmul pentru desfășurarea meciurilor în etape. Creează o coadă Q și stivele WIN și LOSE. Actualizează echipele în coadă și stive, afișează meciurile echipelor câștigătoare și returnează ultimele 8 echipe.
5-cerinta4.c:
Funcția insertNode inserează un nod într-un arbore binar de căutare.
Funcția Display_Descending afișează conținutul arborelui în fișierul r.out în ordine descrescătoare.
Funcția FreeTree eliberează memoria.
Funcția cerinta4 construiește un arbore binar de căutare și afișează conținutul în ordine descrescătoare.
