#include "question2-9.h"

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

void ajouter(struct Noeud **foret, char pos, struct Noeud *node) {
    foret[pos] = node;
}

//Question 06

void supprimer(struct Noeud **foret, char pos) {
    free(foret[pos]);
}

//Question 07

void initialisation(struct match **tab, struct Noeud **foret) {
    struct Noeud *node;
    for (size_t i = 0; i < MAX_ARBRES; ++i) {
        node = malloc(sizeof(struct Noeud));
        node->frequence = tab[i]->nb;
        node->symbole = tab[i]->ch;
        node->droite = NULL;
        node->gauche = NULL;
        ajouter(foret, i, node);
    }
}

//Question 08
//Dans la question 02 on demande l'orde decroissant et maintenant l'ordre croissant ^^
//Je le fais en decroissant c'est mieux

int fusion(struct Noeud **foret) {
    size_t i = 0;
    while (i < MAX_ARBRES && foret[i] != NULL)
        ++i;
    if (i <= 1)
        return 0;
    struct Noeud *node = malloc(sizeof(struct Noeud));
    node->symbole = 0;
    node->frequence = foret[i]->frequence + foret[i-1]->frequence;
    node->gauche = foret[i-1];
    node->droite = foret[i];
    supprimer(foret, i);
    foret[i] = NULL;
    foret[i-1] = node;
    return 42;
}

//Question 09

void fusion_iteree(struct Noeud **foret) {
    while (fusion(foret) == 42) {}
}

//Question 10 dans les fichiers question10.c et question10.h
