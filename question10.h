#ifndef _Q10_
#define _Q10_

#include "main.h"

struct Table {
    struct Table *next;
    char ch;
    char code;
};

char addBin(char a, char bin);
struct Table* constructTable(struct Noeud *foret, char a, struct Table *tab);
void getTable(struct Noeud **foret, struct Table *tab);

#endif
