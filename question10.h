#ifndef _Q10_
#define _Q10_

#include "question2-9.h"

struct Table {
    struct Table *next;
    size_t code;
    char ch;
};

char addBin(size_t code, char bin);
struct Table* constructTable(struct Noeud *foret, size_t code, struct Table *tab);
void getTable(struct Noeud **foret, struct Table *tab);

#endif
