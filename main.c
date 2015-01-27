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
    struct match **tmp = malloc(256 * sizeof(struct match*));
    initTab(tmp);
    size_t i = 0;
    for (i = 0; i < (size_t)size; ++i)
        ++(tmp[tab[i]]->nb);
    free(tab);
    sortDesc(tmp);
    for (i = 0; i < 256 && tmp[i]->nb > 0; ++i) {
        //On affiche que les caracteres lisibles
        if (tmp[i]->ch >= 32 && tmp[i]->ch < 127) {
            printf("%c ", tmp[i]->ch);
            printf("= %zu\n", tmp[i]->nb);
        }
    }
    deleteArray(tmp);
    free(tmp);
    return 0;
}

//Question 02

static inline
void swap(struct match **tab, size_t a, size_t b) {
    struct match *aux = tab[a];
    tab[a] = tab[b];
    tab[b] = aux;
}

void sortDesc(struct match **tab) {
    size_t stop, i, j;
    for (i = 255; i > 1; --i) {
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
    for (size_t i = 0; i < 256; ++i) {
        tmp[i] = malloc(sizeof(struct match));
        tmp[i]->ch = (char)i;
        tmp[i]->nb = 0;
    }
}

void deleteArray(struct match **tab) {
    for (size_t i = 0; i < 256; ++i)
        free(tab[i]);
}

//Question 05

void ajouter(struct Noeud *tab[], char pos, int val, char sym) {
    tab[pos] = malloc(sizeof(struct Noeud));
    tab[pos]->frequence = val;
    tab[pos]->symbole = sym;
}

//Question 06

void supprimer (struct Noeud *tab[], char pos) {
    free(tab[pos]);
}

//Question 07

void initialisation (struct match **tab, struct Noeud *foret[]) {
    for (size_t i = 0; i < 256; ++i)
        ajouter(foret, i, (int)tab[i]->nb, tab[i]->ch);
}
