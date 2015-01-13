#include "main.h"

int main() {
    char *tab = malloc(10000*10000);
    /*lecture du fichier et enregistrement dans un tableau*/
    FILE *texte = fopen("texte.txt","r");
    if(!texte)
    {
        printf("ERREUR fichier impossible à ouvrir\n");
        exit(1);
    }
    fscanf (texte,"%c", tab);
    //Je fais un tableau de 256 pour chaque caractere ASCII
    struct match *tmp = malloc(256*sizeof(struct match));
    while (*tab != '\0') {
        ++(tmp[*tab].nb);
        ++tab;
    }
    sortDesc(tmp);
    for (size_t i = 0; i < 256; ++i) {
        printf("%c", tmp[i].ch);
        printf(" = %zu\n", tmp[i].nb);
    }
    //Faudra free() mais j'ai la flemme la...
    return 0;
}

static inline
void swap(struct match *tab, char a, char b) {
    size_t aux = tab[a].nb;
    char auxc = tab[a].ch;
    tab[a].nb = tab[b].nb;
    tab[a].ch = tab[b].ch;
    tab[b].nb = aux;
    tab[b].ch = auxc;
}

void sortDesc(struct match *tab) {
    char stop, i, j;
    for (i = 255; i > 0; --i) {
        stop = 1;
        for (j = 0; j < i; ++j) {
            if (tab[j].nb > tab[j+1].nb) {
                swap(tab, j, j+1);
                stop = 0;
            }
        }
        if (stop == 1)
            return;
    }
}

void initTab(struct match *tab) {
    for (size_t i = 0; i < 256; ++i) {
        tab[i].ch = (char)i;
        tab[i].nb = 0;
    }
}
