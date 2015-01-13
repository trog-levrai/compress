#include <stdio.h>
#include <stdlib.h>

struct match {
    size_t nb;
    char ch;
};

void sortDesc(struct match *tab);
void initTab(struct match *tab);
