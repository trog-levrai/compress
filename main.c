#include "main.h"
int main() {
    FILE *texte = fopen("foo","r");
    if(!texte)
    {
        printf("ERREUR fichier impossible à ouvrir\n");
        exit(1);
    }
    fseek(texte, 0, SEEK_END);
    long size = ftell(texte) + 1;
    char *tab = malloc(size);
    fseek(texte, SEEK_SET, 0);
    char *aux = malloc(size);
    while (fgets(aux, size, texte) != NULL)
        strcat(tab, aux);
    free(aux);
    fclose(texte);
    //tab de 95 elem pour chaque caractere ASCII qui nous interesse
    struct match **tmp = malloc(95 * sizeof(struct match*));
    initTab(tmp);
    size_t i = 0;
    while (i < (size_t)size) {
        if (tab[i] >= 32) {
            ++(tmp[tab[i] - 32]->nb);
        }
        ++i;
    }
    free(tab);
    sortDesc(tmp);
    for (i = 0; i < 95 && tmp[i]->nb > 0; ++i) {
        printf("%c", tmp[i]->ch);
        printf(" = %zu\n", tmp[i]->nb);
    }
    deleteArray(tmp);
    free(tmp);
    return 0;
}
static inline
void swap(struct match **tab, char a, char b) {
    struct match *aux = tab[a];
    tab[a] = tab[b];
    tab[b] = aux;
}
void sortDesc(struct match **tab) {
    char stop, i, j;
    for (i = 94; i > 1; --i) {
        stop = 1;
        for (j = 0; j < i; ++j) {
            if (tab[j]->nb < tab[j+1]->nb) {
                swap(tab, j, j+1);
                stop = 0;
            }
        }
        if (stop == 1)
            return;
    }
}
void initTab(struct match **tmp) {
    struct match *aux;
    for (size_t i = 0; i < 95; ++i) {
        aux = malloc(sizeof(struct match));
        tmp[i] = aux;
        tmp[i]->ch = (char)(i+32);
        tmp[i]->nb = 0;
    }
}
void deleteArray(struct match **tab) {
    for (char i = 0; i < 95; ++i)
        free(tab[i]);
}
