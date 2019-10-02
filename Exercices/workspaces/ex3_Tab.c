#include <stdio.h>

#define SIZ 10

void main(void) {

    /*creation d'un tableu de taille 10*/
    int tab[SIZ] = {1};
    int jj = 0;
    int tmp=1;

    /*Initialisation du tableau avec toutes les premières puissances de 10*/
    for(jj=1;jj<SIZ;jj++) {
        tab[jj] = tmp*10 ;
        tmp=tab[jj];
    }

    /*afficher toutes les valeurs du tableau par ordre croissant*/
    for(jj=0;jj<SIZ;jj++) {
        printf("%d\n", tab[jj]);
        usleep(250000);
    }

    /*afficher toutes les valeurs du tableau par ordre décroissant*/
    for(jj=SIZ-1;jj>=0;jj--) {
        printf("%d\n",  tab[jj]);
        usleep(250000);
    }

}