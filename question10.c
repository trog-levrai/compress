#include "question10.h"

char addBin(char a, char bin) {
    a<<1;
    a += bin;
    return a;
}

struct Table* constructTable(struct Noeud *foret, char a, struct Table *tab) {
    //Si feuille, alors on ajoute a la table
    if (foret->gauche == NULL) {
        tab->next = malloc(sizeof(struct Table));
        tab = tab->next;
        tab->ch = foret->symbole;
        tab->code = a;
        tab->next = NULL;
        return tab;
    }
    tab = constructTable(foret->gauche, addBin(a, 0), tab);
    return constructTable(foret->droite, addBin(a, 1), tab);
}

void getTable(struct Noeud **foret, struct Table *tab) {
    tab = malloc(sizeof(struct Table));
    tab->next = NULL;
    tab->ch = 0;
    tab->code = 0;
    constructTable(foret[0], 0, tab);
}
