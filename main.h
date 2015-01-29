#ifndef _MAIN_H_
#define _MAIN_H_

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

#include "question10.h"

void sortDesc(struct match **tab);
void initTab(struct match **tmp);
void deleteArray(struct match **tab);
void ajouter(struct Noeud **tab, char pos, struct Noeud *node);
void supprimer(struct Noeud **tab, char pos);
void initialisation(struct match **tab, struct Noeud **foret);
int fusion(struct Noeud **foret);
void fusion_iteree(struct Noeud **foret);

#endif
