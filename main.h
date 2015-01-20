#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct match {
    size_t nb;
    char ch;
};

void sortDesc(struct match **tab);
void initTab(struct match **tmp);
void deleteArray(struct match **tab);
