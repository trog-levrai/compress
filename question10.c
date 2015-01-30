#include "question10.h"

char addBin(size_t code, char bin) {
    code<<1;
    code += bin;
    return code;
}

struct Table* constructTable(struct Noeud *foret, size_t code, struct Table *tab) {
    //Si feuille, alors on ajoute a la table
    if (foret->gauche == NULL) {
        tab->next = malloc(sizeof(struct Table));
        tab = tab->next;
        tab->ch = foret->symbole;
        tab->code = code;
        tab->next = NULL;
        return tab;
    }
    tab = constructTable(foret->gauche, addBin(code, 0), tab);
    return constructTable(foret->droite, addBin(code, 1), tab);
}

void getTable(struct Noeud **foret, struct Table *tab) {
    tab = malloc(sizeof(struct Table));
    tab->next = NULL;
    tab->ch = 0;
    tab->code = 0;
    constructTable(foret[0], 0, tab);
}
