#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARBRES 256

struct match {
    size_t nb;
    char ch;
};

struct Noeud {
    int frequence;
    char symbole;
    struct Noeud *droite;
    struct Noeud *gauche;
};

void sortDesc(struct match **tab);
void initTab(struct match **tmp);
void deleteArray(struct match **tab);
void ajouter(struct Noeud **tab, char pos, struct Noeud *node);
void supprimer(struct Noeud **tab, char pos);
void initialisation(struct match **tab, struct Noeud **foret);
void fusion(struct Noeud **foret);
